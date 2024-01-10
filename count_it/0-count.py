#!/usr/bin/python3
"""
Recursive function that queries the Reddit API, parses the title of all hot
articles, and prints a sorted count of given keywords.
"""

import requests


def count_words(subreddit, word_list, after=None, count_dict=None):
    """
    Count the occurrences of given keywords in the titles of hot articles.
    Print the results in descending order by count and alphabetically.

    subreddit: a string representing the subreddit to search
    word_list: a list of keywords to count
    after: a string representing the last post ID to start the search
    count_dict: a dictionary to store the count of each keyword
    """

    # Base case: stop recursion if word_list is empty
    if not word_list:
        return

    # Initialize count_dict if not provided
    if count_dict is None:
        count_dict = {}

    # API endpoint for querying hot articles in the subreddit
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'

    # Headers to mimic a web browser and avoid API access issues
    headers = {"User-agent": "agent"}

    # Parameters for the API request
    params = {'limit': 100, 'after': after}

    # Make the API request
    response = requests.get(url, headers=headers, params=params,
                            allow_redirects=False)

    # Check if the subreddit is valid (no redirect)
    if response.status_code != 200:
        return

    # Get the JSON data from the response
    data = response.json()

    # Get the list of posts from the data
    posts = data.get('data', {}).get('children', [])

    # Update count_dict based on the titles of the posts
    for post in posts:
        title = post.get('data', {}).get('title', '').lower()
        for word in word_list:
            if word.lower() in title:
                count_dict[word] = count_dict.get(word, 0) + title.count(word.lower())

    # Check if there are more posts to fetch
    after = data.get('data', {}).get('after')
    if after:
        count_words(subreddit, word_list, after, count_dict)
    else:
        # Print the results in descending order by count and alphabetically
        sorted_counts = sorted(count_dict.items(), key=lambda x: (-x[1], x[0]))
        for word, count in sorted_counts:
            print(f'{word}: {count}')
