/* ------------
 * Parsing = lexical + syntatical analysis
 * ------------
 * components:
 * 1. lexer(tokenizer): scan input and generate tokens
 * 2. IR or AST: forms the relations between tokens
 *
 * Token e.g.
 * { type: 'paren',  value: '('   },
 * { type: 'name',   value: 'add' },
 * { type: 'number', value: '2'   },
 *
 * AST e.g.
 *
 * - Program
 *   - CallExpression
 *     - NumberLiteral
 *     - CallExpression
 *       - NumberLiteral
 *       - NumberLiteral
 *
 * --------------
 * Trasnformation
 * --------------
 * Manipulate AST nodes or create a new AST targeting a new language
 *
 * ---------------
 * Code generation
 * ---------------
 * Generate machine code to target
 *
 *
 * ---------------
 * Implementation
 * ---------------
 * # lexer
 * curr: current cursor in the file
 * skip whitespace for token
 *
 * c++ keywords
 * operator
 * variables types: int, char
 *
 * # parser
 * walk() tokens
 * skip parenthesis
 *
 * # IR
 * # Codegen
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

enum class tokenAttr {
  KEYWORD,
  IDENTIFIER,
  OPERATOR,
  UNKNOWN
};

enum class keyword {
  BREAK,
  CASE,
  CHAR,
  CONST,
  CONTINUE,
  DEFAULT,
  DO,
  DOUBLE,
  ELSE,
  ENUM,
  FLOAT,
  FOR,
  IF,
  INT,
  LONG,
  RETURN,
  SHORT,
  SIGNED,
  STATIC,
  STRUCT,
  SWITCH,
  TYPEDEF,
  UNION,
  UNSIGNED,
  VOID,
  WHILE
};

typedef std::unordered_map<tokenAttr, std::string> TokenAttrMap;
typedef std::unordered_map<keyword, std::string> KeywordMap;

struct token{
  // reference to enum
  int type;
  std::string value;
  int loc;
  int line;
};

// current cursor in the file
int curr = 0;
// current line in the file
int cline;
// current token
int tk;
// tokens
std::vector<token> tokens;
// token attribute map
TokenAttrMap tokMap;
// keywords map
KeywordMap kwMap;

void init(){
  // token type
  tokMap.insert({tokenAttr::KEYWORD, "KEYWORD"});
  tokMap.insert({tokenAttr::IDENTIFIER, "IDENTIFIER"});
  tokMap.insert({tokenAttr::OPERATOR, "OPERATOR"});
  tokMap.insert({tokenAttr::UNKNOWN, "UNKNOWN"});
  // keywords
  kwMap.insert({keyword::BREAK ,"BREAK"});
  kwMap.insert({keyword::CASE ,"CASE"});
  kwMap.insert({keyword::CHAR ,"CHAR"});
  kwMap.insert({keyword::CONST ,"CONST"});
  kwMap.insert({keyword::CONTINUE ,"CONTINUE"});
  kwMap.insert({keyword::DEFAULT ,"DEFAULT"});
  kwMap.insert({keyword::DO, "DO"});
  kwMap.insert({keyword::DOUBLE, "DOUBLE"});
  kwMap.insert({keyword::ELSE, "ELSE"});
  kwMap.insert({keyword::ENUM, "ENUM"});
  kwMap.insert({keyword::FLOAT, "FLOAT"});
  kwMap.insert({keyword::FOR, "FOR"});
  kwMap.insert({keyword::IF, "IF"});
  kwMap.insert({keyword::INT, "INT"});
  kwMap.insert({keyword::LONG, "LONG"});
  kwMap.insert({keyword::RETURN, "RETURN"});
  kwMap.insert({keyword::SHORT, "SHORT"});
  kwMap.insert({keyword::SIGNED, "SIGNED"});
  kwMap.insert({keyword::STATIC, "STATIC"});
  kwMap.insert({keyword::STRUCT, "STRUCT"});
  kwMap.insert({keyword::SWITCH, "SWITCH"});
  kwMap.insert({keyword::TYPEDEF, "TYPEDEF"});
  kwMap.insert({keyword::UNION, "UNION"});
  kwMap.insert({keyword::UNSIGNED, "UNSIGNED"});
  kwMap.insert({keyword::VOID, "VOID"});
  kwMap.insert({keyword::WHILE, "WHILE"});
}

void next(){
  // todo: extract tokens
}

bool openfile(std::string filename){
  // binary mode: don't apply format to characters
  std::ifstream in (filename, std::ifstream::binary);
  if (in){
    // end pos
    in.seekg(0, in.end);
    // get the total length of the source file
    size_t length = in.tellg();
    // back to the start pos
    in.seekg(0, in.beg);

    in.close();
    return true;
  }

  return false;
}

int main(int argc, char **argv){
  if (argc > 0 && argv[1] == nullptr){
    std::cout << "Please enter filename.\n";
    return 1;
  }

  bool o = openfile(argv[1]);
  if (!o) return 1;

  init();
  // scan the program
  cline = 1;

  while(tk){
    next();
  }

  return 0;
}
