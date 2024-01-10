#!/usr/bin/python3
'''Get ALL hot posts'''
import requests

BASE_URL = 'http://reddit.com/r/{}/hot.json'


def count_words(subreddit, word_list):
    '''Get ALL hot posts'''
    headers = {'User-agent': 'Unix:0-subs:v1'}
    params = {'limit': 100}

    hot_list = fetch_all_hot_posts(subreddit, headers, params)
    count = count_occurrences(word_list, hot_list)
    print_results(count)


def fetch_all_hot_posts(subreddit, headers, params, after=None, hot_list=[]):
    '''Fetch ALL hot posts recursively'''
    if after == "STOP":
        return hot_list

    if isinstance(after, str) and after != "STOP":
        params['after'] = after

    response = requests.get(BASE_URL.format(subreddit),
                            headers=headers, params=params)

    if response.status_code != 200:
        return hot_list

    data = response.json().get('data', {})
    after = data.get('after', 'STOP')
    if not after:
        after = "STOP"

    hot_list += [
        post.get('data', {}).get('title')
        for post in data.get('children', [])
    ]

    return fetch_all_hot_posts(subreddit, headers, params, after, hot_list)


def count_occurrences(word_list, hot_list):
    '''Count occurrences of keywords in hot posts'''

    # Dictionary to count the frequency of each keyword
    count = {word: 0 for word in word_list}

    # Iterate over each post title and count the occurrences of each keyword

    for title in hot_list:
        for word in word_list:
            for title_word in title.lower().split():
                if title_word == word.lower():
                    count[word] += 1
    # Filter keywords with count greater than zero
    return {k: v for k, v in count.items() if v > 0}


def print_results(count):
    '''
    Print the results sorted in descending order by frequency and
    alphabetically in case of a tie
    '''
    words = list(count.keys())
    for word in sorted(words, reverse=True, key=lambda k: count[k]):
        print("{}: {}".format(word, count[word]))
