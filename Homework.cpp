#include <iostream>
#include <vector>

template <typename T>
class Container {
 private: 
	std::vector<T> data;

 public:
	T& front() {
		return data.front();
	}

	T& back() {
		return data.back();
	}

	void push_front(const T& value) {
        data.insert(data.begin(), value);
    }

	void push_back(const T& value) {
        data.push_back(value);
    }

	void pop_front() {
        if (!data.empty())
            data.erase(data.begin());
    }

	void pop_back() {
        if (!data.empty())
            data.pop_back();
    }

	void insert(size_t pos, const T& value) {
        if (pos <= data.size())
            data.insert(data.begin() + pos, value);
    }

	size_t size() const {
        return data.size();
    }

	typename std::vector<T>::iterator begin() {
        return data.begin();
    }

    typename std::vector<T>::iterator end() {
        return data.end();
    }

	void print() const {
        for (const auto& el : data) {
            std::cout << el << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Container<int> c;

    c.push_back(10);
    c.push_back(20);
    c.push_front(5);
    c.insert(1, 15);

	std::cout << "Elements: ";
    c.print();

	std::cout << "First element: " << c.front() << "\n";
    std::cout << "Last element: " << c.back() << "\n";
    std::cout << "Size: " << c.size() << "\n";

	c.pop_front();
    c.pop_back();

	std::cout << "After pop_front and pop_back: ";
    c.print();

    return 0;
}

// АБО //

#include <iostream>

template <typename T>
class Container {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t count;

public:
    Container() : head(nullptr), tail(nullptr), count(0) {}
    ~Container() { clear(); }

    void push_front(const T& value) {
        Node* node = new Node(value);
        if (!head) head = tail = node;
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        count++;
    }

    void push_back(const T& value) {
        Node* node = new Node(value);
        if (!tail) head = tail = node;
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        count++;
    }

    void pop_front() {
        if (!head) return;
        Node* tmp = head;
        head = head->next;
        if (head) head->prev = nullptr; else tail = nullptr;
        delete tmp;
        count--;
    }

    void pop_back() {
        if (!tail) return;
        Node* tmp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr; else head = nullptr;
        delete tmp;
        count--;
    }

    T& front() { return head->data; }
    T& back()  { return tail->data; }
    size_t size() const { return count; }

    T& operator[](size_t index) {
        if (index >= count) throw std::out_of_range("Index out of range");
        Node* cur = head;
        for (size_t i = 0; i < index; i++) cur = cur->next;
        return cur->data;
    }

    int find(const T& value) {
        Node* cur = head;
        size_t pos = 0;
        while (cur) {
            if (cur->data == value) return pos;
            cur = cur->next;
            pos++;
        }
        return -1;
    }


    void remove(const T& value) {
        Node* cur = head;
        while (cur) {
            if (cur->data == value) {
                Node* toDelete = cur;
                if (cur->prev) cur->prev->next = cur->next;
                else head = cur->next;
                if (cur->next) cur->next->prev = cur->prev;
                else tail = cur->prev;
                cur = cur->next;
                delete toDelete;
                count--;
            } else {
                cur = cur->next;
            }
        }
    }

    void reverse() {
        Node* cur = head;
        Node* temp = nullptr;
        while (cur) {
            temp = cur->prev;
            cur->prev = cur->next;
            cur->next = temp;
            cur = cur->prev;
        }
        if (temp) {
            temp = temp->prev;
            tail = head;
            head = temp;
        }
    }

    void clear() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = nullptr;
        count = 0;
    }

    class Iterator {
        Node* node;
    public:
        Iterator(Node* n) : node(n) {}
        T& operator*() { return node->data; }
        Iterator& operator++() { node = node->next; return *this; }
        bool operator!=(const Iterator& other) const { return node != other.node; }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }

    void print() const {
        Node* cur = head;
        while (cur) {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << "\n";
    }
};

int main() {
    Container<int> c;

    c.push_back(1);
    c.push_back(2);
    c.push_back(3);
    c.push_back(2);
    c.push_back(5);

    std::cout << "List: ";
    c.print();

    std::cout << "Find 3: position = " << c.find(3) << "\n";

    std::cout << "Element [2]: " << c[2] << "\n";

    c.remove(2);
    std::cout << "After remove(2): ";
    c.print();

    c.reverse();
    std::cout << "After reverse: ";
    c.print();

    c.clear();
    std::cout << "After clear, size = " << c.size() << "\n";

    return 0;
}


