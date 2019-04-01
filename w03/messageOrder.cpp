// messageOrder.cpp
// https://www.hackerrank.com/challenges/messages-order/problem
// Callum Howard, 2019


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
    friend class MessageFactory;
public:
    Message() {}
    const string& get_text() const {
        return text;
    }
    bool operator<(const Message& rhs) const {
        return id < rhs.id;
    }
private:
    Message(const std::string& input_text, int order) : text{input_text}, id{order} {}
    std::string text;
    int id;
};

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        return Message(text, messageCount++);
    }
private:
    int messageCount = 0;
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
    static void send_messages(vector<Message> messages, Recipient& recipient) {
        random_shuffle(messages.begin(), messages.end());
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
