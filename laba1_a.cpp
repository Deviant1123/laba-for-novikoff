#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class BookType { ART, TECH };

class Book {
public:
	Book(const std::string& author, const std::string& title, const BookType& type) : _author(author), _title(title), _type(type) {};
	virtual ~Book() {};
	BookType getType() const { return _type; };
	std::string GetAuthor() const { return _author; };
	std::string GetTitle() const { return _title; };
private:
	std::string _author;
	std::string _title;
	const BookType _type;
};

class Library {
public:
	void addBook(const std::string& author, const std::string& title,const BookType& type) {
		if (author.empty() or title.empty()) {
			std::cout << "error" << std::endl;
		}
		books.push_back(Book(author,title,type));
	};
	std::vector <Book> books;
};
void countBooksSwitch(const std::vector <Book>& books) {
	int countArt = 0;
	int countTech = 0;
	for (Book book : books) {
		switch (book.getType()) {
		case BookType::ART:
			++countArt;
			break;
		case BookType::TECH:
			++countTech;
			break;
		}
	}
	std::cout << "count of Fiction but with switch:" << countArt << std::endl;
	std::cout << "count of non Fiction but wuth switch:" << countTech << std::endl;
}
void countBooksNoSwitch(const std::vector <Book>& books) {
	int countArt = 0;
	int countTech = 0;
	for (const Book& book : books) {
		if (book.getType() == BookType::ART) {
			++countArt;
		}
		else {
			++countTech;
		}
	}
	std::cout << "count of fiction:" << countArt << std::endl;
	std::cout << "count of non fiction:" << countTech << std::endl;
}

int main() {
	Library myLibrary;
	myLibrary.addBook("Agatha Christie", "Poirot's early cases ", BookType::ART);
	myLibrary.addBook("Zamyatin", "We", BookType::ART);
	myLibrary.addBook("George Orwell", "1984", BookType::ART);
	myLibrary.addBook("Dostoevsky", "Idiot", BookType::ART);
	myLibrary.addBook("Nassim Nicholas Taleb", "The Black Swan", BookType::TECH);
	myLibrary.addBook("Michael Lewis", "Flash Boys", BookType::TECH);
	countBooksSwitch(myLibrary.books);
	countBooksNoSwitch(myLibrary.books);
	return 0;
}