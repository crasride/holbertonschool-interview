#!/usr/bin/python3
"""0-count module"""

import requests
import collections


def count_words(subreddit, word_list):
    """
    Finds occurrences of specified keywords in a given subreddit.

    Prints keyword along with their occurrences in descending order. Keywords
    with no matches are skipped.

    :param subreddit: string containing subreddit to search
    :param word_list: list of keywords to search for

    :return: OrderedDict with keys as keywords and occurrences as values or
            None on request failure
    """

    def fill_list(after=None, hot_list=[]):
        """
        Recursively creates list of words in hot titles of specified subreddit

        :param after: pagination for the next entry
        :param hot_list: list to populate

        :return: populated list or None on failure
        """
        req = requests.get("https://www.reddit.com/r/{}/hot.json?after={}".
                        format(subreddit, after),
                        headers={"User-agent": "agent"},
                        allow_redirects=False)
        if req.status_code != 200:
            return None
        after = req.json().get("data").get("after")
        if after is None:
            return hot_list
        for i in req.json().get("data").get("children"):
            for word in i.get("data").get("title").split():
                hot_list.append(word.lower())
        return fill_list(after, hot_list)

    if subreddit is None or subreddit == "" or word_list is None:
        return None
    hot_list = fill_list()
    if hot_list is None:
        return None
    all_cnt = collections.Counter(hot_list)
    filtered_cnt = {}
    for word in word_list:
        word_l = word.lower()
        if all_cnt[word_l] > 0:
            if word in filtered_cnt:
                filtered_cnt[word] += filtered_cnt[word]
            else:
                filtered_cnt[word] = all_cnt[word_l]
    for k, v in sorted(filtered_cnt.items(),
                    key=lambda item: item[1], reverse=True):
        print("{}: {}".format(k, v))
    return filtered_cnt
