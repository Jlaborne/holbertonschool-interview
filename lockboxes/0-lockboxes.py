#!/usr/bin/python3
""" defines method to solve lockboxes problem """


def canUnlockAll(boxes):
    """
    Determines if all boxes can be unlocked.

    Parameters:
        boxes(list): List of lists representing boxes and the keys inside them
            - There are n boxes labeled from 0 to n-1.
            - A key with the same number as a box unlocks that box.
            - All keys are positive integers.
            - There can be boxes without keys and keys without boxes.
            - The first box boxes[0] is unlocked initially.

    Returns:
        True if all boxes can be unlocked, False otherwise.
    """
    if len(boxes) < 1:
        return True

    keys = set()
    new_keys = set(boxes[0])

    while len(new_keys):
        keys = keys | new_keys
        new_keys = set()

        if keys.issuperset(range(1, len(boxes))):
            return True

        for key in keys:
            if key < len(boxes):
                for new_key in boxes[key]:
                    if new_key not in keys:
                        new_keys.add(new_key)

    return False
