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

struct token{
  std::string type;
  std::string value;
};

int main(int argc, char **argv){
  if (argc > 0 && argv[1] == nullptr){
    std::cout << "Please enter filename.\n";
    return 1;
  }

  std::fstream fs;

  fs.open(argv[1], std::fstream::in);

  char c;
  while(fs.get(c))
    if (c != '\n'){
      std::cout << c;
    }

  fs.close();

  return 0;
}
