%{
    #include <iostream>
    #include "node.h"
    #include "stdio.h"
    #include <map>
    #include <assert.h>
    #define YYDEBUG 1
    #define YYERROR_VERBOSE

    Node *RootNode; /* the top level root node of our final AST */

    extern int yylex();
    void yyerror(const char *s) { printf("ERROR: %sn", s); }

    std::map<std::string, std::string> IdTable;

    std::string GetType(std::string ori_type) {
      if (ori_type == "int" || ori_type == "char") {
        return "int_char";
      }
      else if (ori_type == "double" || ori_type == "float") {
        return "double_float";
      }
      return "";
    }

    std::string MoreAccurate(std::string t1, std::string t2) {
      if (t1 == "double_float") {
        return "double_float";
      } else if (t2 == "double_float") {
        return "double_float";
      }
      else {
        return "int_char";
      }
    }
%}

/* Represents the many different ways we can access our data */

%union {
    Node *start;
    Node *stmt;
    Node *stmts;
    Node *comp_stmt;
    Node *type;
    Node *args_list;
    Node *arg;
    Node *factor;
    Node *term;
    Node *expr;
    Node *expr_alg;
    Node *expr_and_decl;
    Node *identifier;
    char *str;
}


/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
%token <string> INT CHAR FLOAT DOUBLE IF ELSE WHILE FOR
%token <str> TIDENTIFIER TINTEGER TDOUBLE TCHAR
%token <token> TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL
%token <token> TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TDOT TSEMICOLON
%token <token> TPLUS TMINUS TMUL TDIV TMOD TSADD TSMINUS
%token <token> TREAD TWRITE
%token <token> TNOT TAND TOR
%token <token> TBNOT TBAND TBOR TBXOR
%token <token> TBLEFT TBRIGHT
%token <token> TRETURN

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */
%type <expr> expr0 expr1 expr2 expr3 expr4 expr5 expr6 expr7 expr8 expr9 expr10 expr11 expr12 optional_expr
//%type <block> program stmts block
%type <stmt> stmt matched_stmt open_stmt
//%type <token> comparison


/* Operator precedence for mathematical operators */
%left TPLUS TMINUS
%left TMUL TDIV TMOD
%left TAND TOR
%left TBAND TBOR TBXOR
%left TCEQ TCNE
%left TBLEFT TBRIGHT
%right TEQUAL

%start start

%%

start : INT TIDENTIFIER TLPAREN TRPAREN comp_stmt { RootNode = $<stmt>5; }
      ;

comp_stmt : TLBRACE stmts TRBRACE { $<stmt>$ = $<stmt>2; }
          | TSEMICOLON { $<stmt>$ = new Node("SEMICOLON"); }
          ;

stmts : stmt stmts { $<stmt>$ = $<stmt>2;
                     std::vector<Node*>::iterator it;
                     it = $<stmt>$->Children.begin();
                     $<stmt>$->Children.insert(it, $<stmt>1); }
      | /* empty */ { $<stmt>$ = new Node("COMP_STMT"); }
      ;

stmt : matched_stmt { $<stmt>$ = $<stmt>1; }
     | open_stmt { $<stmt>$ = $<stmt>1; }
     ;

matched_stmt : IF TLPAREN expr TRPAREN matched_stmt ELSE matched_stmt {
                                    $<stmt>$ = new Node("STMT", "IF");
                                    $<stmt>3->NodeInfo = "CONDITION";
                                    $<stmt>5->NodeInfo = "IF BRANCH";
                                    $<stmt>7->NodeInfo = "ELSE BRANCH";
                                    $<stmt>$->Children.push_back($<stmt>3);
                                    $<stmt>$->Children.push_back($<stmt>5);
                                    $<stmt>$->Children.push_back($<stmt>7); }
             | expr_and_decl TSEMICOLON { $<stmt>$ = new Node("STMT", "EXPR");
                                          $<stmt>$->Children.push_back($<expr>1); }
             | comp_stmt { $<stmt>$ = $<stmt>1; }
             | TREAD TLPAREN identifier TRPAREN TSEMICOLON {
                                    $<stmt>$ = new Node("STMT", "READ");
                                    $<stmt>$->Children.push_back($<expr>3); }
             | TWRITE TLPAREN expr TRPAREN TSEMICOLON {
                                    $<stmt>$ = new Node("STMT", "WRITE");
                                    $<stmt>$->Children.push_back($<expr>3); }
             | WHILE TLPAREN expr_and_decl TRPAREN matched_stmt {
                                    $<stmt>$ = new Node("STMT", "WHILE");
                                    $<expr>3->NodeInfo = "CONDITION";
                                    $<stmt>$->Children.push_back($<expr>3);
                                    $<stmt>$->Children.push_back($<stmt>5); }
             | FOR TLPAREN optional_expr TSEMICOLON optional_expr TSEMICOLON optional_expr TRPAREN matched_stmt {
                                    $<stmt>$ = new Node("STMT", "FOR");
                                    $<expr>3->NodeInfo = "START";
                                    $<expr>5->NodeInfo = "CONDITION";
                                    $<expr>7->NodeInfo = "ITER_ACTION";
                                    $<stmt>$->Children.push_back($<expr>3);
                                    $<stmt>$->Children.push_back($<expr>5);
                                    $<stmt>$->Children.push_back($<expr>7);
                                    $<stmt>$->Children.push_back($<stmt>9); }
             | TRETURN expr TSEMICOLON{ $<stmt>$ = new Node("STMT", "RET");
                              $<stmt>$->Children.push_back($<expr>2); }
             ;

open_stmt : IF TLPAREN expr TRPAREN stmt {
                                    $<stmt>$ = new Node("STMT", "IF");
                                    $<stmt>3->NodeInfo = "CONDITION";
                                    $<stmt>5->NodeInfo = "IF BRANCH";
                                    $<stmt>$->Children.push_back($<stmt>3);
                                    $<stmt>$->Children.push_back($<stmt>5); }
          | IF TLPAREN expr TRPAREN matched_stmt ELSE open_stmt {
                                    $<stmt>$ = new Node("STMT", "IF");
                                    $<stmt>3->NodeInfo = "CONDITION";
                                    $<stmt>5->NodeInfo = "IF BRANCH";
                                    $<stmt>7->NodeInfo = "ELSE BRANCH";
                                    $<stmt>$->Children.push_back($<stmt>3);
                                    $<stmt>$->Children.push_back($<stmt>5);
                                    $<stmt>$->Children.push_back($<stmt>7); }
          ;

expr_and_decl : expr { $<expr>$ = $<expr>1; }
              | type args_list { $<expr>$ = new Node("EXPR", "DECL");
                                 std::string t = GetType($<type>1->NodeValue);
                                 for (auto arg : $<args_list>2->Children) {
                                   std::string var = arg->Children[0]->NodeValue;
                                   if (IdTable.find(var) == IdTable.end()) {
                                     IdTable[var] = t;
                                     arg->Children[0]->type = t;
                                   }
                                   else {
                                     std::cout << "Error: Replicated Declaration: " << var << std::endl;
                                   }
                                 }
                                 $<expr>$->Children.push_back($<type>1);
                                 $<expr>$->Children.push_back($<expr>2); }
              ;

type : INT     { $<type>$ = new Node("TYPE", "int"); }
     | CHAR    { $<type>$ = new Node("TYPE", "char"); }
     | FLOAT   { $<type>$ = new Node("TYPE", "float"); }
     | DOUBLE  { $<type>$ = new Node("TYPE", "double"); }
     ;

args_list : arg { $<args_list>$ = new Node("ARGS_LIST");
                  $<args_list>$->Children.push_back($<expr>1); }
          | arg TCOMMA args_list {
                          $<args_list>$ = $<args_list>3;
                          std::vector<Node*>::iterator it;
                          it = $<args_list>$->Children.begin();
                          $<args_list>$->Children.insert(it, $<expr>1); }
           ;

arg : identifier TEQUAL expr { $<expr>$ = new Node("EXPR", "DECL_ASSIGN");
                               assert($<expr>1->IsLit == false);
                               $<expr>$->Children.push_back($<expr>1);
                               $<expr>$->Children.push_back($<expr>3); }
    | identifier { assert($<expr>1->IsLit == false);
                   $<expr>$ = new Node("EXPR", "DECL_ARG");
                   $<expr>$->Children.push_back($<expr>1); }
    ;

expr : expr1 TEQUAL expr { $<expr>$ = new Node("EXPR", "ASSIGN");
                            $<expr>$->Children.push_back($<expr>1);
                            $<expr>$->Children.push_back($<expr>3);
                            assert($<expr>1->IsLit == false);
                          }
     | expr12 { $<expr>$ = $<expr>1; }
     ;

optional_expr : expr_and_decl { $<expr>$ = $<expr>1; }
              | /* empty */ { $<expr>$ = new Node("OPTIONAL_EXPR", "EMPTY"); }
              ;

expr12 : expr11 TOR expr12 { $<expr>$ = new Node("EXPR", "OR");
                             assert($<expr>1->type == "int_char" || $<expr>1->type == "double_float");
                             assert($<expr>3->type == "int_char" || $<expr>3->type == "double_float");
                             $<expr>$->type = "int_char";
                             if ($<expr>1->IsLit && $<expr>3->IsLit) {
                               $<expr>$->IsLit = true;
                               if (std::stod($<expr>1->NodeValue) != 0.0 || std::stod($<expr>3->NodeValue) != 0.0) {
                                 $<expr>$->NodeValue = "1";
                               }
                               else {
                                 $<expr>$->NodeValue = "0";
                               }
                             } else {
                               $<expr>$->Children.push_back($<factor>1);
                               $<expr>$->Children.push_back($<term>3);
                             }
                           }
       | expr11 { $<expr>$ = $<expr>1; }
       ;

expr11 : expr10 TAND expr11 { $<expr>$ = new Node("EXPR", "AND");
                             assert($<expr>1->type == "int_char" || $<expr>1->type == "double_float");
                             assert($<expr>3->type == "int_char" || $<expr>3->type == "double_float");
                             $<expr>$->type = "int_char";
                             if ($<expr>1->IsLit && $<expr>3->IsLit) {
                               $<expr>$->IsLit = true;
                               if (std::stod($<expr>1->NodeValue) != 0.0 && std::stod($<expr>3->NodeValue) != 0.0) {
                                 $<expr>$->NodeValue = "1";
                               }
                               else {
                                 $<expr>$->NodeValue = "0";
                               }
                             } else {
                               $<expr>$->Children.push_back($<factor>1);
                               $<expr>$->Children.push_back($<term>3);
                             }
                           }
       | expr10 { $<expr>$ = $<expr>1; }
       ;

expr10 : expr9 TBOR expr10 { $<expr>$ = new Node("EXPR", "BOR");
                             assert($<expr>1->type == "int_char");
                             assert($<expr>3->type == "int_char");
                             $<expr>$->type = "int_char";
                             if ($<expr>1->IsLit && $<expr>3->IsLit) {
                               $<expr>$->IsLit = true;
                               $<expr>$->NodeValue = std::to_string(std::stoi($<expr>1->NodeValue) | std::stoi($<expr>3->NodeValue));
                             } else {
                               $<expr>$->Children.push_back($<factor>1);
                               $<expr>$->Children.push_back($<term>3);
                             }
                           }
       | expr9 { $<expr>$ = $<expr>1; }
       ;

expr9 : expr8 TBXOR expr9 { $<expr>$ = new Node("EXPR", "BXOR");
                            assert($<expr>1->type == "int_char");
                            assert($<expr>3->type == "int_char");
                            $<expr>$->type = "int_char";
                            if ($<expr>1->IsLit && $<expr>3->IsLit) {
                              $<expr>$->IsLit = true;
                              $<expr>$->NodeValue = std::to_string(std::stoi($<expr>1->NodeValue) ^ std::stoi($<expr>3->NodeValue));
                            } else {
                              $<expr>$->Children.push_back($<factor>1);
                              $<expr>$->Children.push_back($<term>3);
                            }
                          }
      | expr8 { $<expr>$ = $<expr>1; }
      ;

expr8 : expr7 TBAND expr8 { $<expr>$ = new Node("EXPR", "TBAND");
                            assert($<expr>1->type == "int_char");
                            assert($<expr>3->type == "int_char");
                            $<expr>$->type = "int_char";
                            if ($<expr>1->IsLit && $<expr>3->IsLit) {
                              $<expr>$->IsLit = true;
                              $<expr>$->NodeValue = std::to_string(std::stoi($<expr>1->NodeValue) & std::stoi($<expr>3->NodeValue));
                            } else {
                              $<expr>$->Children.push_back($<factor>1);
                              $<expr>$->Children.push_back($<term>3);
                            }
                          }
      | expr7 { $<expr>$ = $<expr>1; }
      ;

expr7 : expr6 TCEQ expr7 { $<expr>$ = new Node("EXPR", "COMP_EQL");
                           assert($<expr>1->type == "int_char" || $<expr>1->type == "double_float");
                           assert($<expr>3->type == "int_char" || $<expr>3->type == "double_float");
                           $<expr>$->type = "int_char";
                           if ($<expr>1->IsLit && $<expr>3->IsLit) {
                             $<expr>$->IsLit = true;
                             if (std::stod($<expr>1->NodeValue) == std::stod($<expr>3->NodeValue))
                               $<expr>$->NodeValue = "1";
                             else
                               $<expr>$->NodeValue = "0";
                           } else {
                             $<expr>$->Children.push_back($<factor>1);
                             $<expr>$->Children.push_back($<term>3);
                           }
                         }
       | expr6 TCNE expr7 { $<expr>$ = new Node("EXPR", "COMP_NE");
                            assert($<expr>1->type == "int_char" || $<expr>1->type == "double_float");
                            assert($<expr>3->type == "int_char" || $<expr>3->type == "double_float");
                            $<expr>$->type = "int_char";
                            if ($<expr>1->IsLit && $<expr>3->IsLit) {
                              $<expr>$->IsLit = true;
                              if (std::stod($<expr>1->NodeValue) != std::stod($<expr>3->NodeValue))
                                $<expr>$->NodeValue = "1";
                              else
                                $<expr>$->NodeValue = "0";
                            } else {
                              $<expr>$->Children.push_back($<factor>1);
                              $<expr>$->Children.push_back($<term>3);
                            }
                          }
       | expr6 { $<expr>$ = $<expr>1; }
       ;

expr6 : expr5 TCLT expr6 { $<expr>$ = new Node("EXPR", "COMP_LT");
                           assert($<expr>1->type == "int_char" || $<expr>1->type == "double_float");
                           assert($<expr>3->type == "int_char" || $<expr>3->type == "double_float");
                           $<expr>$->type = "int_char";
                           if ($<expr>1->IsLit && $<expr>3->IsLit) {
                             $<expr>$->IsLit = true;
                             if (std::stod($<expr>1->NodeValue) < std::stod($<expr>3->NodeValue))
                               $<expr>$->NodeValue = "1";
                             else
                               $<expr>$->NodeValue = "0";
                           } else {
                             $<expr>$->Children.push_back($<factor>1);
                             $<expr>$->Children.push_back($<term>3);
                           }
                         }
       | expr5 TCGT expr6 { $<expr>$ = new Node("EXPR", "COMP_GT");
                            assert($<expr>1->type == "int_char" || $<expr>1->type == "double_float");
                            assert($<expr>3->type == "int_char" || $<expr>3->type == "double_float");
                            $<expr>$->type = "int_char";
                            if ($<expr>1->IsLit && $<expr>3->IsLit) {
                              $<expr>$->IsLit = true;
                              if (std::stod($<expr>1->NodeValue) > std::stod($<expr>3->NodeValue))
                                $<expr>$->NodeValue = "1";
                              else
                                $<expr>$->NodeValue = "0";
                            } else {
                              $<expr>$->Children.push_back($<factor>1);
                              $<expr>$->Children.push_back($<term>3);
                            }
                          }
       | expr5 TCLE expr6 { $<expr>$ = new Node("EXPR", "COMP_LE");
                            assert($<expr>1->type == "int_char" || $<expr>1->type == "double_float");
                            assert($<expr>3->type == "int_char" || $<expr>3->type == "double_float");
                            $<expr>$->type = "int_char";
                            if ($<expr>1->IsLit && $<expr>3->IsLit) {
                              $<expr>$->IsLit = true;
                              if (std::stod($<expr>1->NodeValue) <= std::stod($<expr>3->NodeValue))
                                $<expr>$->NodeValue = "1";
                              else
                                $<expr>$->NodeValue = "0";
                            } else {
                              $<expr>$->Children.push_back($<factor>1);
                              $<expr>$->Children.push_back($<term>3);
                            }
                          }
       | expr5 TCGE expr6 { $<expr>$ = new Node("EXPR", "COMP_GE");
                            assert($<expr>1->type == "int_char" || $<expr>1->type == "double_float");
                            assert($<expr>3->type == "int_char" || $<expr>3->type == "double_float");
                            $<expr>$->type = "int_char";
                            if ($<expr>1->IsLit && $<expr>3->IsLit) {
                              $<expr>$->IsLit = true;
                              if (std::stod($<expr>1->NodeValue) >= std::stod($<expr>3->NodeValue))
                                $<expr>$->NodeValue = "1";
                              else
                                $<expr>$->NodeValue = "0";
                            } else {
                              $<expr>$->Children.push_back($<factor>1);
                              $<expr>$->Children.push_back($<term>3);
                            }
                          }
       | expr5 { $<expr>$ = $<expr>1; }
      ;

expr5 : expr4 TBLEFT expr5 { $<expr>$ = new Node("EXPR", "BLEFT");
                             assert($<expr>1->type == "int_char");
                             assert($<expr>3->type == "int_char");
                             $<expr>$->type = "int_char";
                             if ($<expr>1->IsLit && $<expr>3->IsLit) {
                               $<expr>$->IsLit = true;
                               $<expr>$->NodeValue = std::to_string(std::stoi($<expr>1->NodeValue) << std::stoi($<expr>3->NodeValue));
                             } else {
                               $<expr>$->Children.push_back($<factor>1);
                               $<expr>$->Children.push_back($<term>3);
                             }
                           }
      | expr4 TBRIGHT expr5 { $<expr>$ = new Node("EXPR", "BRIGHT");
                              assert($<expr>1->type == "int_char");
                              assert($<expr>3->type == "int_char");
                              $<expr>$->type = "int_char";
                              if ($<expr>1->IsLit && $<expr>3->IsLit) {
                                $<expr>$->IsLit = true;
                                $<expr>$->NodeValue = std::to_string(std::stoi($<expr>1->NodeValue) >> std::stoi($<expr>3->NodeValue));
                              } else {
                                $<expr>$->Children.push_back($<factor>1);
                                $<expr>$->Children.push_back($<term>3);
                              }
                            }
      | expr4 { $<expr>$ = $<expr>1; }
      ;

expr4 : expr4 TPLUS expr3 { $<expr>$ = new Node("EXPR", "ADD");
                            assert($<expr>1->type == "int_char" || $<expr>1->type == "double_float");
                            assert($<expr>3->type == "int_char" || $<expr>3->type == "double_float");
                            $<expr>$->type = MoreAccurate($<expr>1->type, $<expr>3->type);
                            if ($<expr>1->IsLit && $<expr>3->IsLit) {
                              $<expr>$->IsLit = true;
                              if ($<expr>$->type == "int_char")
                                $<expr>$->NodeValue = std::to_string(std::stoi($<expr>1->NodeValue) + std::stoi($<expr>3->NodeValue));
                              else
                                $<expr>$->NodeValue = std::to_string(std::stod($<expr>1->NodeValue) + std::stod($<expr>3->NodeValue));
                            } else {
                              $<expr>$->Children.push_back($<factor>1);
                              $<expr>$->Children.push_back($<term>3);
                            }
                          }
      | expr4 TMINUS expr3 { $<expr>$ = new Node("EXPR", "MINUS");
                             assert($<expr>1->type == "int_char" || $<expr>1->type == "double_float");
                             assert($<expr>3->type == "int_char" || $<expr>3->type == "double_float");
                             $<expr>$->type = MoreAccurate($<expr>1->type, $<expr>3->type);
                             if ($<expr>1->IsLit && $<expr>3->IsLit) {
                               $<expr>$->IsLit = true;
                               if ($<expr>$->type == "int_char")
                                 $<expr>$->NodeValue = std::to_string(std::stoi($<expr>1->NodeValue) - std::stoi($<expr>3->NodeValue));
                               else
                                 $<expr>$->NodeValue = std::to_string(std::stod($<expr>1->NodeValue) - std::stod($<expr>3->NodeValue));
                             } else {
                               $<expr>$->Children.push_back($<factor>1);
                               $<expr>$->Children.push_back($<term>3);
                             }
                           }
      | expr3 { $<expr>$ = $<expr>1; }
      ;

expr3 : expr2 TMUL expr3 { $<expr>$ = new Node("EXPR", "MUL");
                          assert($<expr>1->type == "int_char" || $<expr>1->type == "double_float");
                          assert($<expr>3->type == "int_char" || $<expr>3->type == "double_float");
                          $<expr>$->type = MoreAccurate($<expr>1->type, $<expr>3->type);
                          if ($<expr>1->IsLit && $<expr>3->IsLit) {
                            $<expr>$->IsLit = true;
                            if ($<expr>$->type == "int_char")
                              $<expr>$->NodeValue = std::to_string(std::stoi($<expr>1->NodeValue) * std::stoi($<expr>3->NodeValue));
                            else
                              $<expr>$->NodeValue = std::to_string(std::stod($<expr>1->NodeValue) * std::stod($<expr>3->NodeValue));
                          } else {
                            $<expr>$->Children.push_back($<factor>1);
                            $<expr>$->Children.push_back($<term>3);
                          }
                        }
     | expr2 TDIV expr3 { $<expr>$ = new Node("EXPR", "DIV");
                          assert($<expr>1->type == "int_char" || $<expr>1->type == "double_float");
                          assert($<expr>3->type == "int_char" || $<expr>3->type == "double_float");
                          $<expr>$->type = MoreAccurate($<expr>1->type, $<expr>3->type);
                          if ($<expr>1->IsLit && $<expr>3->IsLit) {
                            $<expr>$->IsLit = true;
                            if ($<expr>$->type == "int_char")
                              $<expr>$->NodeValue = std::to_string(std::stoi($<expr>1->NodeValue) / std::stoi($<expr>3->NodeValue));
                            else
                              $<expr>$->NodeValue = std::to_string(std::stod($<expr>1->NodeValue) / std::stod($<expr>3->NodeValue));
                          } else {
                            $<expr>$->Children.push_back($<factor>1);
                            $<expr>$->Children.push_back($<term>3);
                          }
                        }
     | expr2 TMOD expr3 { $<expr>$ = new Node("EXPR", "MOD");
                          assert($<expr>1->type == "int_char");
                          assert($<expr>3->type == "int_char");
                          $<expr>$->type = "int_char";
                          if ($<expr>1->IsLit && $<expr>3->IsLit) {
                            $<expr>$->IsLit = true;
                            $<expr>$->NodeValue = std::to_string(std::stoi($<expr>1->NodeValue) % std::stoi($<expr>3->NodeValue));
                          } else {
                            $<expr>$->Children.push_back($<factor>1);
                            $<expr>$->Children.push_back($<term>3);
                          }
                        }
     | expr2 { $<term>$ = $<term>1; }
     ;

expr2 : TMINUS TINTEGER { $<factor>$ = new Node("VAL", $2, "NEG", "int_char");
                          $<expr>$->IsLit = true; }
      | TPLUS TINTEGER { $<factor>$ = new Node("VAL", $2, "", "int_char");
                         $<expr>$->IsLit = true; }
      | TSADD identifier { $<expr>$ = new Node("EXPR", "PRSADD");
                           assert($<expr>2->type == "int_char");
                           $<expr>$->type = "int_char";
                           $<expr>$->Children.push_back($<expr>2); }
      | TSMINUS identifier { $<expr>$ = new Node("EXPR", "PRSMINUS");
                             assert($<expr>2->type == "int_char");
                             $<expr>$->type = "int_char";
                             $<expr>$->Children.push_back($<expr>2); }
      | identifier TSADD { $<expr>$ = new Node("EXPR", "SUSADD");
                           assert($<expr>2->type == "int_char");
                           $<expr>$->type = "int_char";
                           $<expr>$->Children.push_back($<expr>2); }
      | identifier TSMINUS { $<expr>$ = new Node("EXPR", "SUSMINUS");
                             assert($<expr>2->type == "int_char");
                             $<expr>$->type = "int_char";
                             $<expr>$->Children.push_back($<expr>2); }
      | TNOT expr1 { $<expr>$ = new Node("EXPR", "NOT");
                     assert($<expr>2->type == "int_char" || $<expr>2->type == "double_float");
                     $<expr>$->type = "int_char";
                     if ($<expr>2->IsLit) {
                        $<expr>$->IsLit = true;
                        if (std::stod($<expr>2->NodeValue) != 0.0) {
                          $<expr>$->NodeValue = "0";
                        } else {
                          $<expr>$->NodeValue = "1";
                        }
                     } else {
                        $<expr>$->Children.push_back($<expr>2);
                     } }
      | TBNOT expr1 { $<expr>$ = new Node("EXPR", "BNOT");
                      assert($<expr>2->type == "int_char");
                      $<expr>$->type = "int_char";
                      if ($<expr>2->IsLit) {
                        $<expr>$->IsLit = true;
                        $<expr>$->NodeValue = std::to_string(~std::stoi($<expr>2->NodeValue));
                      } else {
                        $<expr>$->Children.push_back($<expr>2);
                      } }
      | expr1 { $<term>$ = $<term>1; }
      ;

expr1 : TLPAREN expr TRPAREN { $<expr>$ = $<expr>2; }
      | expr0 { $<factor>$ = $<expr>1; }
      ;

expr0 : identifier { $<factor>$ = $<expr>1; }
      | TINTEGER { $<factor>$ = new Node("VAL", $1, "", "int_char");
                   $<expr>$->IsLit = true; }
      | TDOUBLE { $<factor>$ = new Node("VAL", $1, "", "double_float");
                  $<expr>$->IsLit = true; }
      | TCHAR { $<factor>$ = new Node("VAL", $1, "", "int_char");
                $<expr>$->IsLit = true; }
      ;

identifier : TIDENTIFIER { $<identifier>$ = new Node("VAR", $1);
                           std::string var = $1;
                           if (IdTable.find(var) != IdTable.end()) {
                             $<identifier>$->type = IdTable.find(var)->second;
                           }
                          }
           ;

%%
