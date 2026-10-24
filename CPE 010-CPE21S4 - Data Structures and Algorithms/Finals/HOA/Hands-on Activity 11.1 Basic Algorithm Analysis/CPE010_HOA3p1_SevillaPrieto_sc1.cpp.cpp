#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

class Student {
private:
    pair<int, int> name;
    bool vaccinated;

public:
    Student(pair<int, int> n, bool v) : name(n), vaccinated(v) {}

    pair<int, int> get_name() const { return name; }
    bool is_vaccinated() const { return vaccinated; }

    bool operator==(const Student& p) const {
        return this->name == p.name;
    }

    bool operator<(const Student& p) const {
        return this->name < p.name;
    }

    bool operator>(const Student& p) const {
        return this->name > p.name;
    }
};

auto generate_random_Student(int max) {
    random_device rd;
    mt19937 rand(rd());
    uniform_int_distribution<mt19937::result_type> uniform_dist(1, max);

    auto random_name = make_pair(uniform_dist(rand), uniform_dist(rand));
    bool is_vaccinated = uniform_dist(rand) % 2 ? true : false;
    return Student(random_name, is_vaccinated);
}

bool needs_vaccination(Student p, vector<Student>& people) {
    auto first = people.begin();
    auto last = people.end();

    while (true) {
        auto range_length = distance(first, last);
        auto mid_element_index = floor(range_length / 2);
        auto mid_element = *(first + mid_element_index);

        if (mid_element == p && mid_element.is_vaccinated() == false)
            return true;
        else if (mid_element == p && mid_element.is_vaccinated() == true)
            return false;
        else if (mid_element > p)
            advance(last, -mid_element_index);
        else if (mid_element < p)
            advance(first, mid_element_index);

        if (range_length == 1)
            return true;
    }
}

void search_test(int size, Student p) {
    vector<Student> people;

    for (auto i = 0; i < size; i++)
        people.push_back(generate_random_Student(size));

    sort(people.begin(), people.end());

    auto begin = chrono::steady_clock::now();

    bool search_result = needs_vaccination(p, people);

    auto end = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::microseconds>(end - begin).count();

    cout << "Time taken to search = " << elapsed << " microseconds" << endl;
    cout << "Student (" << p.get_name().first << " " << p.get_name().second << ") ";
    if (search_result)
        cout << "needs vaccination." << endl;
    else
        cout << "does not need vaccination." << endl;
}

int main() {
    auto p = generate_random_Student(1000);
    search_test(1000, p);
    search_test(10000, p);
    search_test(100000, p);
    return 0;
}