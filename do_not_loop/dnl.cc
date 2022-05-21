#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

size_t min_elt_length(const std::vector<std::string>& req)
{
    std::vector<std::string> res = req;
    std::sort(res.begin(), res.end(),
              [](const std::string& pointer, const std::string& res) {
                  return pointer.size() < res.size();
              });
    auto size = res.front().size();
    return size;
}

size_t max_elt_length(const std::vector<std::string>& req)
{
    std::vector<std::string> vector_of_strings = req;
    std::sort(vector_of_strings.begin(), vector_of_strings.end(),
              [](const std::string& pos, const std::string& vector_of_strings) {
                  return pos.size() > vector_of_strings.size();
              });
    auto resultat = vector_of_strings.front().size();
    return resultat;
}

size_t help_function(const std::vector<std::string>& req,
                     std::vector<std::string> vector, size_t size)
{
    if (!vector.empty())
    {
        size += vector.back().size();
        vector.pop_back();
        size = help_function(req, vector, size);
    }
    return size;
}

size_t sum_elt_length(const std::vector<std::string>& req)
{
    std::vector<std::string> vector_of_strings = req;
    size_t size = 0;
    if (!vector_of_strings.empty())
        size = help_function(req, vector_of_strings, size);
    return size;
}

size_t count_elt(const std::vector<std::string>& req, const std::string& elt)
{
    std::vector<std::string> res = req;
    size_t size = std::count(res.begin(), res.end(), elt);
    return size;
}

size_t count_duplicate(const std::vector<std::string>& req)
{
    std::vector<std::string> list = req;
    std::sort(list.begin(), list.end());
    auto doppel_ganger = std::unique(list.begin(), list.end());
    list.erase(doppel_ganger, list.end());
    return req.size() - list.size();
}