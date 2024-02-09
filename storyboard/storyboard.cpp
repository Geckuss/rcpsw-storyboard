// This is a simple storyboard application that allows users to add and search notes.
// The application consists of two classes: Note and Storyboard.
// The Note class represents a single note with a title, text, and tags.
// The Storyboard class manages a collection of notes and provides methods to add and search notes.
// The application is tested with hardcoded notes and search tests.

#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>

class Note
{
public:
    std::string title; // The title of the note
    std::string text; // The text of the note
    std::unordered_set<std::string> tags; // The tags associated with the note

    Note(const std::string& title, const std::string& text, const std::unordered_set<std::string>& tags)
        : title(title), text(text), tags(tags)
    {
    }
};

class Storyboard
{
public:
    std::vector<Note> notes; // The collection of notes in the storyboard

    // Adds a new note to the storyboard
    void addNote(const Note& note)
    {
        notes.push_back(note);
        std::cout << "Added note with title: " << note.title << std::endl;
    }

    // Searches for notes in the storyboard based on their title
    std::vector<Note> searchByTitle(const std::string& title)
    {
        std::vector<Note> result;
        for (const auto& note : notes)
        {
            if (note.title == title)
            {
                result.push_back(note);
            }
        }
        std::cout << "Searched notes by title: " << title << std::endl;
        return result;
    }

    // Searches for notes in the storyboard based on their text
    std::vector<Note> searchByText(const std::string& text)
    {
        std::vector<Note> result;
        for (const auto& note : notes)
        {
            if (note.text == text)
            {
                result.push_back(note);
            }
        }
        std::cout << "Searched notes by text: " << text << std::endl;
        return result;
    }

    // Searches for notes in the storyboard based on a specific tag
    std::vector<Note> searchByTag(const std::string& tag)
    {
        std::vector<Note> result;
        for (const auto& note : notes)
        {
            if (note.tags.count(tag) > 0)
            {
                result.push_back(note);
            }
        }
        std::cout << "Searched notes by tag: " << tag << std::endl;
        return result;
    }
};

int main() {
    // Hardcoded tags for testing
    std::unordered_set<std::string> tags1 = {"unit test", "traceplayer"};
    std::unordered_set<std::string> tags2 = {"testing", "spark core"};

    // Hardcoded notes for testing
    Note note1("Test", "Implement a unit test for the class Traceplayer of the spark core framework.", tags1);
    Note note2("Traceplayer", "Implement a unit test for the class Traceplayer of the spark core framework.", tags2);

    // Create a storyboard and add the notes
    Storyboard storyboard;
    storyboard.addNote(note1);
    storyboard.addNote(note2);

    // Hardcoded search tests of notes by title, text, and tag
    std::vector<Note> notesByTitle = storyboard.searchByTitle("Traceplayer");
    std::vector<Note> notesByText = storyboard.searchByText("Implement a unit test for the class Traceplayer of the spark core framework.");
    std::vector<Note> notesByTag = storyboard.searchByTag("testing");

    // Print the found notes
    std::cout << "Notes with title 'Traceplayer':\n";
    for (const Note& note : notesByTitle) {
        std::cout << "Title: " << note.title << "\n";
        std::cout << "Text: " << note.text << "\n";
        std::cout << "Tags: ";
        for (const std::string& tag : note.tags) {
            std::cout << tag << ", ";
        }
        std::cout << "\n\n";
    }

    std::cout << "Notes with text 'Implement a unit test for the class Traceplayer of the spark core framework.':\n";
    for (const Note& note : notesByText) {
        std::cout << "Title: " << note.title << "\n";
        std::cout << "Text: " << note.text << "\n";
        std::cout << "Tags: ";
        for (const std::string& tag : note.tags) {
            std::cout << tag << ", ";
        }
        std::cout << "\n\n";
    }

    std::cout << "Notes with tag 'testing':\n";
    for (const Note& note : notesByTag) {
        std::cout << "Title: " << note.title << "\n";
        std::cout << "Text: " << note.text << "\n";
        std::cout << "Tags: ";
        for (const std::string& tag : note.tags) {
            std::cout << tag << ", ";
        }
        std::cout << "\n\n";
    }

    return 0;
}
// Performance:
// addNote() time complexity: O(1) (It just adds a note to the vector)
// search() time complexity: O(n) (It has to iterate all notes to find matching notes)

// Memory:
// By using vectors, memory is allocated dynamically and the size of the vector can grow as needed.

// Design:
// If performance would have been a concern, I would have used one of the map data structures to achieve better time complexity for search.
// That would cause memory overhead, but it would be a trade-off for better performance.