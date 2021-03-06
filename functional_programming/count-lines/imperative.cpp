
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>

/**
 * Opens a file specified by the filename argument, and counts the number of lines in said file
 */
int count_lines(const std::string &filename)
{
  std::ifstream in(filename);
  in.unsetf(std::ios_base::skipws);

  // Counts newlines from the current position in the stream until the end of the file
  return std::count(std::istream_iterator<char>(in), std::istream_iterator<char>(), '\n');
}

/**
 * Given a list of files, this function returns a list of line counts for each of them
 */
std::vector<int> count_lines_in_files(const std::vector<std::string> &files)
{
  std::vector<int> results;

  for (const auto &file : files) { results.push_back(count_lines(file)); }

  return results;
}

int main()
{
  const std::vector<std::string> files = { "file1.txt", "file2.txt", "file3.txt" };
  auto results = count_lines_in_files(files);

  for (auto i = 0; i < files.size(); ++i) { std::cout << files.at(i) << " has " << results.at(i) << " line(s)\n"; }
  return 0;
}
