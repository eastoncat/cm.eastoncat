<?php

/**
 * @file
 * Feeds parser class for MediaRSS
 */

/**
 * Class definition for MediaRSS Parser.
 *
 * Parses RSS or Atom feeds returned from YouTube API like.
 */
class MediaCloudcastFeedsParser extends FeedsMediaRSSParser {

  /**
   * Parse the extra mapping sources provided by this parser.
   *
   * @param $fetcher_result FeedsFetcherResult
   * @param $source FeedsSource
   *
   * @see FeedsParser::parse()
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {

    $mediarss_feed = $fetcher_result->getRaw();

    $result = parent::parse($source, $fetcher_result);

    /**
     * @see common_syndication_parser_parse()
     */
    if (!defined('LIBXML_VERSION') || (version_compare(phpversion(), '5.1.0', '<'))) {
      @$sxml = simplexml_load_string($mediarss_feed, NULL);
    }
    else {
      @$sxml = simplexml_load_string($mediarss_feed, NULL, LIBXML_NOERROR | LIBXML_NOWARNING | LIBXML_NOCDATA);
    }

    // Got a malformed XML.
    if ($sxml === FALSE || is_null($sxml)) {
      throw new Exception(t('MediaCloudcastFeedsParser: Malformed XML source.'));
    }

    // Run parsing if the feed is Atom or RSS
    if ($this->isAtomFeed($sxml)) {
      $result = $this->parseAtom($result, $sxml, $source, $fetcher_result);
    }
    elseif ($this->isRssFeed($sxml)) {
      $result = $this->parseRss20($result, $sxml, $source, $fetcher_result);
    }
    else {
      throw new Exception(t('MediaCloudcastFeedsParser: Unknown type of feed.'));
    }

    return $result;
  }

  /**
   * Check if given feed object is an Atom feed.
   *
   * @param SimpleXMLElement $sxml
   *
   * @return boolen
   *   TRUE if given SimpleXML object is Atom feed or FALSE
   */
  protected function isAtomFeed(SimpleXMLElement $sxml) {
    return $sxml->getName() == 'feed';
  }

  /**
   * Check if given feed object is a RSS feed.
   *
   * @param SimpleXMLElement $sxml
   *
   * @return boolen
   *   TRUE if given SimpleXML object is RSS feed or FALSE
   */
  protected function isRssFeed(SimpleXMLElement $sxml) {
    return $sxml->getName() == 'rss';
  }

  /**
   * Add the extra mapping sources provided by this parser.
   */
  public function getMappingSources() {
    return parent::getMappingSources() + array(
      'cloudcast_program' => array(
        'name' => t('Cloudcast Program'),
      ),
      'cloudcast_episode' => array(  //5.1
        'name' => t('Cloudcast Episode'),
      ),
      'cloudcast_summary' => array(  //5.2
        'name' => t('Cloudcast Summary'),
      ),
    );
  }

 /**
   * Parse Atom feed
   *
   * @param SimpleXMLElement $sxml
   * @param FeedsFetcherResult $fetcher_result
   * @param FeedsSource $source
   */
  private function parseAtom(FeedsParserResult $result, SimpleXMLElement $sxml, FeedsSource $source, FeedsFetcherResult $fetcher_result) {

    // XML was parsed successfully, so we can begin to process items
    foreach ($sxml->entry as $entry) {
      $this->parseItem($result, $entry);
    }

    return $result;
  }

  /**
   * Parse RSS 2.0 feed
   *
   * @param SimpleXMLElement $sxml
   * @param FeedsFetcherResult $fetcher_result
   * @param FeedsSource $source
   */
  private function parseRss20(FeedsParserResult $result, SimpleXMLElement $sxml, FeedsSource $source, FeedsFetcherResult $fetcher_result) {

    // XML was parsed successfully, so we can begin to process items
    foreach ($sxml->xpath('//item') as $entry) {
      $this->parseItem($result, $entry);
    }

    return $result;
  }

  /**
   *
   */
  private function parseItem(FeedsParserResult &$result, SimpleXMLElement $entry) {
    // Get nodes in cloudcast: namespace for cloudcast information
    $cloudcast = $entry->children('http://cloudcast.telvue.com/mrss_cloudcast/');

    // Cloudcast feeds do not have guid, using link
    $link = (string) $entry->link;

    foreach ($result->items as $key => $value) {
      if ($value['link'] == $link) {
        // Append the FeedsFetcherResult object with the parsed results.
        $result->items[$key] += array(
          'cloudcast_program' => (string) $cloudcast->program,
          'cloudcast_episode' => (string) $cloudcast->episode,
          'cloudcast_summary' => (string) $cloudcast->summary,
        );
      }
    }
  }
}
