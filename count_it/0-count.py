#!/usr/bin/python3
"""
Recursive function that queries the Reddit API and counts keyword occurrences
"""
import requests


def count_words(subreddit, word_list, word_count=None, after=None):
    if word_count is None:
        word_count = {}

    if not word_list:
        return

    # Prepare lowercase word list and handle duplicates
    if word_count == {}:
        for word in word_list:
            word_l = word.lower()
            if word_l in word_count:
                word_count[word_l] += 0
            else:
                word_count[word_l] = 0

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {'User-Agent': 'holbertonschool-advanced-api'}
    params = {'limit': 100, 'after': after}

    response = requests.get(url, headers=headers,
                            params=params, allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json()
    posts = data.get("data", {}).get("children", [])

    for post in posts:
        title = post["data"]["title"].lower().split()
        for word in word_count:
            word_count[word] += title.count(word)

    after = data["data"].get("after")
    if after:
        return count_words(subreddit, word_list, word_count, after)

    # Sort results
    filtered = {k: v for k, v in word_count.items() if v > 0}
    sorted_words = sorted(filtered.items(), key=lambda x: (-x[1], x[0]))

    for word, count in sorted_words:
        print(f"{word}: {count}")
