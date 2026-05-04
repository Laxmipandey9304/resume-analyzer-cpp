#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string resume;

    cout << "===== Resume Analyzer =====\n";
    cout << "Enter your resume text:\n";

    getline(cin, resume);

    // Convert to lowercase
    transform(resume.begin(), resume.end(), resume.begin(), ::tolower);

    vector<string> skills = {"c++", "html", "css", "javascript", "python", "java", "sql"};

    int score = 0;
    vector<string> matched;
    vector<string> missing;

    // Check skills
    for (string skill : skills) {
        if (resume.find(skill) != string::npos) {
            score += 100 / skills.size();
            matched.push_back(skill);
        } else {
            missing.push_back(skill);
        }
    }

    // Job suggestion
    string job = "General Intern";

    if (resume.find("c++") != string::npos)
        job = "Software Developer";
    else if (resume.find("javascript") != string::npos)
        job = "Web Developer";
    else if (resume.find("python") != string::npos)
        job = "Data Analyst";

    // Output
    cout << "\n===== RESULT =====\n";
    cout << "Score: " << score << "/100\n";

    cout << "Matched Skills: ";
    if (matched.empty()) cout << "None";
    for (string s : matched) cout << s << " ";

    cout << "\nMissing Skills: ";
    if (missing.empty()) cout << "None";
    for (string s : missing) cout << s << " ";

    cout << "\nRecommended Job: " << job << endl;

    return 0;
}