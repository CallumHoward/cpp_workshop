// main.cpp
// https://www.hackerrank.com/challenges/attribute-parser/problem
// Callum Howard, 2019


#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory> // unique_ptr
#include <map>
#include <string> // getline
#include <numeric> // accumulate
#include <exception> // runtime_error
#include <iterator> // next


using SymIt = std::vector<std::string>::const_iterator;

struct Tag {
    std::string name;
    std::map<std::string, std::string> attributes;
    std::vector<Tag> nestedTags;

    const Tag& findNestedTag(const std::string& nestedName) const {
        const auto found = std::find_if(std::cbegin(nestedTags), std::cend(nestedTags),
                [nestedName] (const Tag& tag) { return tag.name == nestedName; });
        if (found == std::cend(nestedTags)) {
            throw std::runtime_error{"Nested tag '" + nestedName + "' not found!"};
        }
        return *found;
    }
};

struct Hrml {
    std::vector<Tag> tags;

    const Tag& findTag(const std::string& name) const {
        const auto found = std::find_if(std::cbegin(tags), std::cend(tags),
                [name] (const Tag& tag) { return tag.name == name; });
        if (found == std::cend(tags)) {
            throw std::runtime_error{"Nested tag '" + name + "' not found!"};
        }
        return *found;
    }
};

struct Token {
    enum TokenT {
        undefined,
        beginTag,
        endTag,
        attributeString,
        attributeLabel,
        assignmentOperator
    };
    std::string string;
    TokenT type;
};

// parsed token group
struct PToken {
    enum PTokenT {
        tagBlock,
        attribute,
        unresolved
    };
    std::vector<Token> tokens;
    PTokenT type;
};

// function prototypes
std::vector<Token> tokenise(const std::string& input);
std::vector<Token> lexer(const std::vector<std::string>& symbols);
std::vector<Tag> parse(const std::vector<Token>& tokens);
std::string lexString(SymIt& tokenBegin, SymIt& it, const SymIt& cend);
std::string lexTag(SymIt& tokenBegin, SymIt& it, Token::TokenT& tokenType);
std::vector<PToken> parsePTokens(const std::vector<Token>& tokens);
std::vector<Tag> processPTokens(const std::vector<PToken>& pTokens);
std::vector<std::string> splitSymbols(const std::string& input);


int main() {
    int numLines, numQueries;
    std::cin >> numLines >> numQueries;
    std::cin.get();  // chomp newline

    // read input text
    auto input = std::string{};
    for (int i = 0; i < numLines; ++i) {
        auto line = std::string{};
        std::getline(std::cin, line);
        input.append(line);
    }

    // read queries
    auto queries = std::vector<std::string>{};
    for (int i = 0; i < numQueries; ++i) {
        auto query = std::string{};
        std::cin >> query;
        queries.push_back(query);
    }

    const auto tokens = tokenise(input);

    // parse lines
    Hrml syntaxTree;
    syntaxTree.tags = parse(tokens);

    // process queries
    for (const auto& query : queries) {

        const auto querySymbols = splitSymbols(query);
        auto currentTag = syntaxTree.findTag(querySymbols.front());

        for (auto it = std::next(std::cbegin(querySymbols));
                it != std::cend(querySymbols); ++it) {

            if (*it == ".") {
                ++it;
                assert(it != std::cend(querySymbols));
                currentTag = currentTag.findNestedTag(*it);

            } else if (*it == "~") {
                ++it;
                assert(it != std::cend(querySymbols));
                if (currentTag.attributes.find(*it) ==
                        std::cend(currentTag.attributes)) {
                    std::cout << "Not Found!\n";
                } else {
                    std::cout << currentTag.attributes.at(*it) << '\n';
                }
                break; // accessing attribute denote the end of a query

            }
        }
    }

    return 0;
}

std::vector<Token> tokenise(const std::string& input) {
    const auto symbols = splitSymbols(input);
    const auto tokens = lexer(symbols);
    return tokens;
}

std::vector<std::string> splitSymbols(const std::string& input) {
    auto symbols = std::vector<std::string>{};
    auto tokenBegin = input.cbegin();
    for (auto it = std::cbegin(input); it != std::cend(input);) {
        tokenBegin = it;
        if (std::isalnum(*it) != 0) {
            while (it != std::cend(input) and std::isalnum(*it) != 0) { ++it; }
            symbols.emplace_back(tokenBegin, it);
        } else {
            ++it;
            symbols.emplace_back(tokenBegin, it);
        }
    }
    return symbols;
}

std::vector<Token> lexer(const std::vector<std::string>& symbols) {
    auto tokens = std::vector<Token>{};
    auto token = Token{};

    for (auto it = std::cbegin(symbols); it != std::cend(symbols); ++it) {
        auto tokenBegin = it;
        if (*it == "\"") {  // attribute string case
            token = Token{lexString(tokenBegin, it, std::cend(symbols)),
                    Token::attributeString};

        } else if (*it == " ") {  // get rid of spaces that aren't within strings
            continue;

        } else if (*it == "<") {  // tag case
            auto tokenType = Token::beginTag;
            token = Token{lexTag(tokenBegin, it, tokenType), tokenType};

        } else if (*it == "=") {
            token = Token{*it, Token::assignmentOperator};

        } else if (std::isalnum((*it).at(0))) {
            token = Token{*it, Token::attributeLabel};

        } else {
            continue;
        }

        tokens.push_back(token);
    }

    return tokens;
}

std::string lexString(SymIt& tokenBegin, SymIt& it, const SymIt& cend) {
    ++it;
    // find closing string delimeter
    while (*it != "\"") {
        if (it == cend) {
            throw std::runtime_error{"Syntax Error: unterminated string"};
        }
        ++it;
    }
    return std::accumulate(tokenBegin + 1, it, std::string{});
}

std::string lexTag(SymIt& tokenBegin, SymIt& it, Token::TokenT& tokenType) {
    ++it;

    // handle end tag case
    if (*it == "/") {
        ++tokenBegin;
        tokenType = Token::endTag;
        // look for the closing angle bracket
        it += 2;
        while (*it == " ") { ++it; }
        if (*it != ">") {
            throw std::runtime_error{"Syntax Error: missing closing angle bracket"};
        }

    } else {  // begin tag case
        ++it;
    }

    return std::accumulate(tokenBegin + 1, it, std::string{});
}

std::vector<PToken> parsePTokens(const std::vector<Token>& tokens) {
    auto pTokens = std::vector<PToken>{};

    // evaluate attributes on first pass
    for (auto it = std::cbegin(tokens); it != std::cend(tokens); ++it) {
        auto pToken = PToken{};
        if (it->type == Token::attributeLabel) {
            pToken.type = PToken::attribute;

            // label
            pToken.tokens.push_back(*it);
            ++it;

            // assignment operator
            if (it->type != Token::assignmentOperator) {
                throw std::runtime_error{"Syntax Error: expected assignment operator "
                        "following attribute label: " + pToken.tokens.front().string};
            }
            pToken.tokens.push_back(*it);
            ++it;

            // value
            if (it->type != Token::attributeString) {
                throw std::runtime_error{"Syntax Error: expected string attribute "
                        "value following attribute assignment operator for "
                        "attribute: " + pToken.tokens.front().string};
            }
            pToken.tokens.push_back(*it);

        } else if (it->type == Token::beginTag or it->type == Token::endTag) {
            pToken.type = PToken::unresolved;
            pToken.tokens.push_back(*it);

        } else {
            throw std::runtime_error{"Syntax Error: unexpected token found: " +
                it->string};
        }

        pTokens.push_back(pToken);
    }

    //std::cout << "======== pTokens ========" << '\n';
    //for (const auto& pToken : pTokens) {
    //    std::cout << pToken.type << '\n';
    //    for (const auto& token : pToken.tokens) {
    //        std::cout << "\t" << token.type << ": " << token.string << '\n';
    //    }
    //}

    return pTokens;
}

std::vector<Tag> parse(const std::vector<Token>& tokens) {
    const auto pTokens = parsePTokens(tokens);
    const auto tags = processPTokens(pTokens);
    return tags;
}

std::vector<Tag> processPTokens(const std::vector<PToken>& pTokens) {
    // create tags recursively from parsed tokens
    auto tags = std::vector<Tag>{};
    for (auto it = std::cbegin(pTokens); it != std::cend(pTokens); ++it) {

        if (it->type != PToken::unresolved) {
            throw std::runtime_error{"Processing Error: Expected opening tag"
                    " for: " + it->tokens.front().string};
        }

        auto tag = Tag{};
        tag.name = it->tokens.front().string;
        assert(it != std::cend(pTokens));
        ++it;

        // get attributes
        while (it->type == PToken::attribute) {
            tag.attributes[it->tokens.front().string] = it->tokens.back().string;
            assert(it != std::cend(pTokens));
            ++it;
        }

        // get nested child tags
        while (it->type == PToken::unresolved and
                it->tokens.front().type == Token::beginTag) {

            // find nested tag range
            const auto pTokenBegin = it;
            ++it;
            while (not (it->type == PToken::unresolved and
                    it->tokens.front().type == Token::endTag)) {
                if (it == std::cend(pTokens)) {
                    throw std::runtime_error{"Processing Error: Could not find "
                            "closing tag for: " + pTokenBegin->tokens.front().string};
                }
                assert(it != std::cend(pTokens));
                ++it;
            }

            // handle closing tag of nested tag range
            if (pTokenBegin->tokens.front().string != it->tokens.front().string) {
                throw std::runtime_error{"Processing Error: Tags don't match: " +
                        pTokenBegin->tokens.front().string + " and " +
                        it->tokens.front().string};
            }
            assert(it != std::cend(pTokens));
            ++it;

            // process nested tag range recursively
            auto nested = std::vector<PToken>{pTokenBegin, it};
            tag.nestedTags = processPTokens(nested);

            // handle closing tag of outer range
            if (it == std::cend(pTokens) or
                    it->type != PToken::unresolved or
                    it->tokens.front().type != Token::endTag) {
                throw std::runtime_error{"Processing Error: Could not find "
                        "closing tag for: " + pTokenBegin->tokens.front().string};
            }

        }

        tags.push_back(tag);
        assert(it != std::cend(pTokens));
    }

    return tags;
}

