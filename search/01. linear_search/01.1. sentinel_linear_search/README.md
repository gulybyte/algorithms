# Sentinel Linear Search

The Sentinel Linear Search algorithm is an optimized variation of the conventional linear search, which adds a special element (the sentinel) at the end of the list. This sentinel allows the search to be terminated as soon as the desired value is found, eliminating the need to check the end of the list at each iteration. This results in a significant reduction in the number of comparisons required.

# The Algorithm
> Flowchart (pseudocode):

![Sentinel linear search algorithm](sentinel_linear_search_flowchart.png)

<h6>Disclaimer: The visualization of a sentinel linear search compared to a regular linear search changes very little, even though the logic between the algorithms differs significantly. In an animated visualization, both algorithms appear almost identical, with only the value of the last index being different. For this reason, I will not adhere to the pattern to insert animations that is in my READMEs.</h6>

# Big-O Complexity for Binary Search
## $$\text{Time Complexity:}$$ $$\Omega(1)$$ $$\Theta(n)$$ $$O(n)$$ $$\text {Space Complexity:}$$ $$O(1) $$
