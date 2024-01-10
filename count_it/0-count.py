#!/usr/bin/python3
'''Get ALL hot posts'''
import requests

BASE_URL = 'http://reddit.com/r/{}/hot.json'


def count_words(subreddit, word_list):
    '''Get ALL hot posts'''
    # Set up headers and parameters for the HTTP request
    headers = {'User-agent': 'Unix:0-subs:v1'}
    params = {'limit': 100}

    # Get the list of titles of the most popular posts
    hot_list = fetch_all_hot_posts(subreddit, headers, params)

    # Count the frequency of each keyword in the list of titles
    count = count_occurrences(word_list, hot_list)

    # Print the results
    print_results(count)


def fetch_all_hot_posts(subreddit, headers, params, after=None, hot_list=[]):
    '''Fetch ALL hot posts recursively'''
    # If there are no more posts, return the cumulative list
    if after == "STOP":
        return hot_list

    # there is an ID of the last processed post add it to the request parameter
    if isinstance(after, str) and after != "STOP":
        params['after'] = after

    # Make the request to the Reddit API
    response = requests.get(BASE_URL.format(subreddit),
                            headers=headers, params=params)

    # Check if the request was successful (status code 200)
    if response.status_code != 200:
        return hot_list

    # Get the JSON data from the response
    data = response.json().get('data', {})

    # Get the ID of the last post for the next request
    after = data.get('after', 'STOP')
    if not after:
        after = "STOP"

    # Add the titles of the posts to the cumulative list
    hot_list += [
        post.get('data', {}).get('title')
        for post in data.get('children', [])
    ]

    # Recursive call to fetch more posts
    return fetch_all_hot_posts(subreddit, headers, params, after, hot_list)


def count_occurrences(word_list, hot_list):
    '''Count occurrences of keywords in hot posts'''
    # Initialize a dictionary to count the frequency of each keyword
    count = {word: 0 for word in word_list}

    # Iterate over each post title and count occurrences of each keyword
    for title in hot_list:
        for word in word_list:
            for title_word in title.lower().split():
                if title_word == word.lower():
                    count[word] += 1

    # Filter keywords with count greater than zero
    return {k: v for k, v in count.items() if v > 0}


def print_results(count):
    '''Print request results'''
    # Sorted in descending order by frequency ,alphabetically in case of ties
    words = list(count.keys())
    for word in sorted(words, reverse=True, key=lambda k: count[k]):
        print("{}: {}".format(word, count[word]))
