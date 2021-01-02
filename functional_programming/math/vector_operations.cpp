
#include <iostream>
#include <numeric>
#include <vector>

// TODO - template the functions
/**
 * Calculates the average score of the vector, imperative version
 */
double average_score_imperative(const std::vector<int> &scores)
{
  int sum = 0;
  for (int score : scores) { sum += score; }
  return sum / (double)scores.size();
}

/**
 * Calculates the average score of the vector with std::accumulate.
 * By default, accumulate uses addition as the folding/reduction operation over a collection
 */
double average_score(const std::vector<int> &scores)
{
  return std::accumulate(scores.cbegin(), scores.cend(), 0) / (double)scores.size();
}

/**
 * Calculates the product score of the vector.
 */
double scores_product(const std::vector<int> &scores)
{
  return std::accumulate(scores.cbegin(), scores.cend(), 1, std::multiplies<int>());
}

int main(int argc, char *argv[])
{
  std::cout << average_score_imperative({ 1, 2, 3, 4 }) << '\n';
  std::cout << average_score({ 1, 2, 3, 4 }) << '\n';
  std::cout << scores_product({ 1, 2, 3, 4 }) << '\n';
}
