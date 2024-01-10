#!/usr/bin/python3
"""
Recursive function to query Reddit API and count occurrences of keywords
"""

import requests


def count_words(subreddit, word_list, after=None, count_dict=None):
    """
    Queries the Reddit API recursively, parses titles, and prints sorted
    count of keywords


    :param subreddit: The subreddit to search
    :param word_list: List of keywords to count
    :param after: The parameter used for pagination
    :param count_dict: Dictionary to store word counts
    """
    base_url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3'}
    params = {'limit': 100, 'after': after}
    response = requests.get(base_url, headers=headers, params=params,
                            allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json().get('data', {})
    children = data.get('children', [])

    if not children:
        return

    if count_dict is None:
        count_dict = {}

    for post in children:
        title = post['data']['title'].lower()
        for word in word_list:
            word = word.lower()
            count_dict[word] = count_dict.get(word, 0) + title.count(word)

    next_page = data.get('after')
    if next_page:
        count_words(subreddit, word_list, next_page, count_dict)
    else:
        print_results(count_dict)


def print_results(count_dict):
    """
    Prints the results in the specified format

    :param count_dict: Dictionary containing word counts
    """
    sorted_results = sorted(count_dict.items(), key=lambda x: (-x[1], x[0]))

    for word, count in sorted_results:
        print("{}: {}".format(word, count))
