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

typedef std::unordered_map<tokenAttr, std::string> TokenAttrMap;

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
// tokens
std::vector<token> tok;
// token attribute map
TokenAttrMap tokMap;

void init(){
  tokMap.insert({tokenAttr::KEYWORD, "KEYWORD"});
  tokMap.insert({tokenAttr::IDENTIFIER, "IDENTIFIER"});
  tokMap.insert({tokenAttr::OPERATOR, "OPERATOR"});
  tokMap.insert({tokenAttr::UNKNOWN, "UNKNOWN"});
}

// token returns a sequence of tokens
void token(std::string str){
  std::cout << str << std::endl;
  // todo: extract each string in a line
  // Every string is separated by whitespace
}

int main(int argc, char **argv){
  if (argc > 0 && argv[1] == nullptr){
    std::cout << "Please enter filename.\n";
    return 1;
  }

  std::fstream fs;

  fs.open(argv[1], std::fstream::in);
  // check if fs is failing
  if (fs){
    std::string str;

    // initiate token types map
    init();
    while(std::getline(fs, str)){
      token(str);
    }

    fs.close();
  }

  return 0;
}
