/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BEG = 258,
     END = 259,
     DECL = 260,
     BEGDECL = 261,
     ENDDECL = 262,
     T_INT = 263,
     T_FLOAT = 264,
     READ = 265,
     WRITE = 266,
     IF = 267,
     THEN = 268,
     ELSE = 269,
     ENDIF = 270,
     FOR = 271,
     WHILE = 272,
     BREAK = 273,
     RET = 274,
     ID = 275,
     NUM = 276,
     FLOAT = 277,
     EQEQ = 278,
     LE = 279,
     GE = 280,
     NE = 281,
     INCR = 282,
     UMINUS = 283
   };
#endif
/* Tokens.  */
#define BEG 258
#define END 259
#define DECL 260
#define BEGDECL 261
#define ENDDECL 262
#define T_INT 263
#define T_FLOAT 264
#define READ 265
#define WRITE 266
#define IF 267
#define THEN 268
#define ELSE 269
#define ENDIF 270
#define FOR 271
#define WHILE 272
#define BREAK 273
#define RET 274
#define ID 275
#define NUM 276
#define FLOAT 277
#define EQEQ 278
#define LE 279
#define GE 280
#define NE 281
#define INCR 282
#define UMINUS 283




/* Copy the first part of user declarations.  */
#line 1 "./src/compiler.y"
	
	#include<bits/stdc++.h>
    #include"lexer.cpp"
	using namespace std;
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();

    extern int lineNo;
	extern FILE *yyin; // Declare yyin to point to the input file

	// Symbol table 
    struct symbolTableNode{

        string dataType;
        string type;
        int lineNo;
		int m;
		int n;
    };
	unordered_map<string, symbolTableNode>symbolTable;

    void insert(string);
	void insert(string,int);
	void insert(string,int,int);
	int lookUp(string);
    void insertType();
    string type;

	struct node{

		string nodeType;
        string data;
		int iVal;
		float fVal;
        node *l;
        node *r;

    };

    struct node * root = nullptr;
    struct node * mknode(struct node*, struct node*, string);
	struct node * mknode(struct node*, struct node*, string, int);
	struct node * mknode(struct node*, struct node*, string, float);
    void preorder(node*, int);

	// MIPS
	string mips = "";
	string gvarMIPS = "";
	string mainStartMIPS = "";
	string mainBodyMIPS = "";
	string mainEndMIPS = "";

	bool cantHandle = false;
	bool cantHandleString = "None";


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 59 "./src/compiler.y"
{ 

	struct var_name { 

		char name[100]; 
		int val;
		float fval;
        struct node *nd;

	} nd_obj; 

}
/* Line 193 of yacc.c.  */
#line 223 "./bin/parser.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 236 "./bin/parser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  137

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    43,     2,     2,    34,     2,     2,
      40,    41,    32,    30,    38,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
      28,    42,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     8,    10,    12,    14,    19,    27,    29,
      33,    37,    38,    41,    45,    47,    49,    51,    54,    57,
      61,    65,    69,    73,    77,    81,    85,    89,    93,    97,
     101,   105,   106,   108,   112,   114,   119,   127,   129,   133,
     137,   139,   142,   147,   152,   159,   160,   165,   174,   175,
     177,   178,   180,   182,   183,   185,   187,   199,   207,   210,
     213,   216,   218,   220,   222,   225,   226
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    53,     3,    70,     4,    -1,     8,    -1,
       9,    -1,    20,    -1,    20,    36,    21,    37,    -1,    20,
      36,    21,    37,    36,    21,    37,    -1,    49,    -1,    49,
      38,    50,    -1,    48,    50,    39,    -1,    -1,    51,    52,
      -1,     5,    52,     7,    -1,    21,    -1,    22,    -1,    56,
      -1,    56,    27,    -1,    27,    56,    -1,    40,    54,    41,
      -1,    54,    30,    54,    -1,    54,    31,    54,    -1,    54,
      32,    54,    -1,    54,    33,    54,    -1,    54,    34,    54,
      -1,    54,    28,    54,    -1,    54,    29,    54,    -1,    54,
      23,    54,    -1,    54,    25,    54,    -1,    54,    24,    54,
      -1,    54,    26,    54,    -1,    -1,    54,    -1,    54,    38,
      55,    -1,    20,    -1,    20,    36,    54,    37,    -1,    20,
      36,    54,    37,    36,    54,    37,    -1,    56,    -1,    56,
      38,    57,    -1,    56,    42,    54,    -1,    20,    -1,    59,
      20,    -1,    10,    40,    57,    41,    -1,    11,    40,    55,
      41,    -1,    11,    40,    43,    59,    43,    41,    -1,    -1,
      14,    44,    70,    45,    -1,    12,    40,    54,    41,    44,
      70,    45,    62,    -1,    -1,    58,    -1,    -1,    58,    -1,
      54,    -1,    -1,    58,    -1,    54,    -1,    16,    40,    64,
      39,    65,    39,    66,    41,    44,    70,    45,    -1,    17,
      40,    54,    41,    44,    70,    45,    -1,    58,    39,    -1,
      60,    39,    -1,    61,    39,    -1,    63,    -1,    67,    -1,
      68,    -1,    18,    39,    -1,    -1,    69,    70,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    95,    95,    99,   100,   103,   108,   113,   120,   124,
     130,   136,   137,   140,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   163,   164,   165,   167,   168,   169,   172,   173,   176,
     179,   180,   183,   186,   187,   190,   191,   194,   197,   198,
     201,   202,   203,   206,   207,   208,   212,   218,   224,   225,
     226,   227,   228,   229,   230,   233,   234
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEG", "END", "DECL", "BEGDECL",
  "ENDDECL", "T_INT", "T_FLOAT", "READ", "WRITE", "IF", "THEN", "ELSE",
  "ENDIF", "FOR", "WHILE", "BREAK", "RET", "ID", "NUM", "FLOAT", "EQEQ",
  "LE", "GE", "NE", "INCR", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "UMINUS", "'['", "']'", "','", "';'", "'('", "')'", "'='", "'\"'",
  "'{'", "'}'", "$accept", "Programme", "RetType", "GlobalID",
  "GlobalIDList", "GlobalDecl", "GlobalDeclList", "GlobalDeclSec", "Expr",
  "ExprList", "VarExpr", "VarExprList", "AssignStmt", "StrExpr",
  "ReadStmt", "WriteStmt", "ElseStmt", "IfStmt", "Forcond1", "Forcond2",
  "Forcond3", "ForStmt", "WhileStmt", "Stmt", "StmtList", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    60,    62,
      43,    45,    42,    47,    37,   283,    91,    93,    44,    59,
      40,    41,    61,    34,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    50,    50,
      51,    52,    52,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    55,    55,    55,    56,    56,    56,    57,    57,    58,
      59,    59,    60,    61,    61,    62,    62,    63,    64,    64,
      65,    65,    65,    66,    66,    66,    67,    68,    69,    69,
      69,    69,    69,    69,    69,    70,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     1,     1,     4,     7,     1,     3,
       3,     0,     2,     3,     1,     1,     1,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     0,     1,     3,     1,     4,     7,     1,     3,     3,
       1,     2,     4,     4,     6,     0,     4,     8,     0,     1,
       0,     1,     1,     0,     1,     1,    11,     7,     2,     2,
       2,     1,     1,     1,     2,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,     0,     0,     3,     4,     0,    11,     0,     1,
      65,     5,     8,     0,    12,    13,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,    61,    62,    63,
      65,     0,     0,     0,    10,     0,    31,     0,    48,     0,
      64,     0,     0,    58,    59,    60,    66,     2,     0,     9,
      37,     0,    14,    15,     0,     0,     0,    32,     0,    16,
       0,    49,     0,     0,     0,    39,     6,     0,    42,    18,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    43,    17,     0,    50,     0,
      35,     0,    38,    19,    41,     0,    27,    29,    28,    30,
      25,    26,    20,    21,    22,    23,    24,    33,    65,    52,
      16,    51,     0,    65,     0,     0,    44,     0,    53,     0,
       0,     7,    45,    55,    54,     0,    57,    36,     0,    47,
       0,    65,    65,     0,     0,    46,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    12,    13,     7,     8,     3,    57,    58,
      59,    51,    24,    72,    25,    26,   129,    27,    62,   112,
     125,    28,    29,    30,    31
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -37
static const yytype_int16 yypact[] =
{
      -4,     1,    18,    16,   -37,   -37,    12,     1,    14,   -37,
      73,     5,   -12,     3,   -37,   -37,     8,     9,    10,    11,
      36,     4,    41,    37,     7,    48,    49,   -37,   -37,   -37,
      73,    88,    24,    12,   -37,    74,   -16,    -5,    74,    -5,
     -37,    -5,    -5,   -37,   -37,   -37,   -37,   -37,    58,   -37,
      59,    55,   -37,   -37,    74,    -5,    79,   142,    60,    75,
     100,   -37,    61,   114,   158,    30,    71,    74,   -37,   -37,
     128,   -37,   -13,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,   -37,   -37,    65,    -5,    67,
      76,    92,   -37,   -37,   -37,    77,     6,     6,     6,     6,
     188,   188,   -20,   -20,    80,    80,   -37,   -37,    73,    30,
     -19,   -37,    78,    73,    -5,    82,   -37,    70,    -5,    90,
     173,   -37,   102,    30,   -37,    86,   -37,   -37,   105,   -37,
     106,    73,    73,    91,   118,   -37,   -37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -37,   -37,   -37,   -37,    87,   -37,   157,   -37,    -8,    93,
     -10,   111,   -36,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -27
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      23,     1,    61,    46,    22,    52,    53,    94,    86,     4,
       5,    54,    81,    82,    83,    22,    52,    53,     9,    10,
      23,    15,    54,    42,    55,    50,    33,    56,    23,    60,
      95,    63,    11,    64,    65,    55,    79,    80,    81,    82,
      83,    32,    34,    40,    69,    48,    43,    70,    35,    36,
      37,    38,   111,    73,    74,    75,    76,    50,    77,    78,
      79,    80,    81,    82,    83,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    39,    41,   110,    42,
     109,   117,   124,    16,    17,    18,   119,    44,    45,    19,
      20,    21,    47,    22,    22,    66,    68,    67,    23,    71,
      88,    85,    86,    23,   133,   134,   120,    91,   110,   108,
     123,   113,   114,   115,    83,   122,   128,   118,   116,   121,
      49,    23,    23,    73,    74,    75,    76,   130,    77,    78,
      79,    80,    81,    82,    83,   126,   135,    73,    74,    75,
      76,    87,    77,    78,    79,    80,    81,    82,    83,   131,
     132,    73,    74,    75,    76,    89,    77,    78,    79,    80,
      81,    82,    83,   136,    14,    73,    74,    75,    76,    93,
      77,    78,    79,    80,    81,    82,    83,   107,    92,     0,
      84,    73,    74,    75,    76,     0,    77,    78,    79,    80,
      81,    82,    83,     0,     0,    90,    73,    74,    75,    76,
       0,    77,    78,    79,    80,    81,    82,    83,     0,     0,
     127,    73,    74,    75,    76,     0,     0,     0,    79,    80,
      81,    82,    83
};

static const yytype_int16 yycheck[] =
{
      10,     5,    38,    30,    20,    21,    22,    20,    27,     8,
       9,    27,    32,    33,    34,    20,    21,    22,     0,     3,
      30,     7,    27,    42,    40,    35,    38,    43,    38,    37,
      43,    39,    20,    41,    42,    40,    30,    31,    32,    33,
      34,    36,    39,    39,    54,    21,    39,    55,    40,    40,
      40,    40,    88,    23,    24,    25,    26,    67,    28,    29,
      30,    31,    32,    33,    34,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    40,    36,    88,    42,
      88,   108,   118,    10,    11,    12,   113,    39,    39,    16,
      17,    18,     4,    20,    20,    37,    41,    38,   108,    20,
      39,    41,    27,   113,   131,   132,   114,    36,   118,    44,
     118,    44,    36,    21,    34,    45,    14,    39,    41,    37,
      33,   131,   132,    23,    24,    25,    26,    41,    28,    29,
      30,    31,    32,    33,    34,    45,    45,    23,    24,    25,
      26,    41,    28,    29,    30,    31,    32,    33,    34,    44,
      44,    23,    24,    25,    26,    41,    28,    29,    30,    31,
      32,    33,    34,    45,     7,    23,    24,    25,    26,    41,
      28,    29,    30,    31,    32,    33,    34,    84,    67,    -1,
      38,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    37,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      37,    23,    24,    25,    26,    -1,    -1,    -1,    30,    31,
      32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    47,    53,     8,     9,    48,    51,    52,     0,
       3,    20,    49,    50,    52,     7,    10,    11,    12,    16,
      17,    18,    20,    56,    58,    60,    61,    63,    67,    68,
      69,    70,    36,    38,    39,    40,    40,    40,    40,    40,
      39,    36,    42,    39,    39,    39,    70,     4,    21,    50,
      56,    57,    21,    22,    27,    40,    43,    54,    55,    56,
      54,    58,    64,    54,    54,    54,    37,    38,    41,    56,
      54,    20,    59,    23,    24,    25,    26,    28,    29,    30,
      31,    32,    33,    34,    38,    41,    27,    41,    39,    41,
      37,    36,    57,    41,    20,    43,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    44,    54,
      56,    58,    65,    44,    36,    21,    41,    70,    39,    70,
      54,    37,    45,    54,    58,    66,    45,    37,    14,    62,
      41,    44,    44,    70,    70,    45,    45
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 95 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj).nd, (yyvsp[(3) - (4)].nd_obj).nd, "Programme"); root = (yyval.nd_obj).nd; ;}
    break;

  case 3:
#line 99 "./src/compiler.y"
    { type = yytext; (yyval.nd_obj).nd = mknode(NULL,NULL,"INT"); ;}
    break;

  case 4:
#line 100 "./src/compiler.y"
    { type = yytext; (yyval.nd_obj).nd = mknode(NULL,NULL,"FLOAT"); ;}
    break;

  case 5:
#line 104 "./src/compiler.y"
    { 
				insert((yyvsp[(1) - (1)].nd_obj).name);  
				(yyval.nd_obj).nd = mknode(NULL,NULL,(yyvsp[(1) - (1)].nd_obj).name);  
			;}
    break;

  case 6:
#line 109 "./src/compiler.y"
    { 
				insert((yyvsp[(1) - (4)].nd_obj).name, (yyvsp[(3) - (4)].nd_obj).val);  
				(yyval.nd_obj).nd = mknode(mknode(NULL,NULL,"NUM",(yyvsp[(3) - (4)].nd_obj).val), NULL, (yyvsp[(1) - (4)].nd_obj).name);
			;}
    break;

  case 7:
#line 114 "./src/compiler.y"
    { 
				insert((yyvsp[(1) - (7)].nd_obj).name, (yyvsp[(3) - (7)].nd_obj).val, (yyvsp[(6) - (7)].nd_obj).val);  
				(yyval.nd_obj).nd = mknode(mknode(NULL,NULL,"NUM",(yyvsp[(3) - (7)].nd_obj).val), mknode(NULL,NULL,"NUM",(yyvsp[(6) - (7)].nd_obj).val), (yyvsp[(1) - (7)].nd_obj).name); 
			;}
    break;

  case 8:
#line 121 "./src/compiler.y"
    { 
				(yyval.nd_obj).nd = (yyvsp[(1) - (1)].nd_obj).nd; 
			  ;}
    break;

  case 9:
#line 125 "./src/compiler.y"
    { 
				(yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj).nd, " "); 
			  ;}
    break;

  case 10:
#line 131 "./src/compiler.y"
    { 
				(yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(2) - (3)].nd_obj).nd, "GlobalDecl"); 
			  ;}
    break;

  case 11:
#line 136 "./src/compiler.y"
    { (yyval.nd_obj).nd = NULL; ;}
    break;

  case 12:
#line 137 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd,(yyvsp[(2) - (2)].nd_obj).nd, "GDecList"); ;}
    break;

  case 13:
#line 140 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd, nullptr, "GlobalDeclSec"); ;}
    break;

  case 14:
#line 144 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode(NULL,NULL,"NUM",(yyvsp[(1) - (1)].nd_obj).val); ;}
    break;

  case 15:
#line 145 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode(NULL,NULL, "FLOAT",(yyvsp[(1) - (1)].nd_obj).fval); ;}
    break;

  case 16:
#line 146 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd,NULL, "VarExpr"); ;}
    break;

  case 17:
#line 147 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd,NULL, "Post Incr"); ;}
    break;

  case 18:
#line 148 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(2) - (2)].nd_obj).nd,NULL, "Pre Incr"); ;}
    break;

  case 19:
#line 149 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(2) - (3)].nd_obj).nd,NULL,"()"); ;}
    break;

  case 20:
#line 150 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd,(yyvsp[(3) - (3)].nd_obj).nd, "+"); ;}
    break;

  case 21:
#line 151 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd,(yyvsp[(3) - (3)].nd_obj).nd, "-"); ;}
    break;

  case 22:
#line 152 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd,(yyvsp[(3) - (3)].nd_obj).nd, "*"); ;}
    break;

  case 23:
#line 153 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd,(yyvsp[(3) - (3)].nd_obj).nd, "/"); ;}
    break;

  case 24:
#line 154 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd,(yyvsp[(3) - (3)].nd_obj).nd, "%"); ;}
    break;

  case 25:
#line 155 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd,(yyvsp[(3) - (3)].nd_obj).nd, "<"); ;}
    break;

  case 26:
#line 156 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd,(yyvsp[(3) - (3)].nd_obj).nd, ">"); ;}
    break;

  case 27:
#line 157 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd,(yyvsp[(3) - (3)].nd_obj).nd, "=="); ;}
    break;

  case 28:
#line 158 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd,(yyvsp[(3) - (3)].nd_obj).nd, ">="); ;}
    break;

  case 29:
#line 159 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd,(yyvsp[(3) - (3)].nd_obj).nd, "<="); ;}
    break;

  case 30:
#line 160 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd,(yyvsp[(3) - (3)].nd_obj).nd, "!="); ;}
    break;

  case 31:
#line 163 "./src/compiler.y"
    { (yyval.nd_obj).nd = NULL; ;}
    break;

  case 32:
#line 164 "./src/compiler.y"
    { (yyval.nd_obj).nd = (yyvsp[(1) - (1)].nd_obj).nd; ;}
    break;

  case 33:
#line 165 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj).nd, "ExprList"); ;}
    break;

  case 34:
#line 167 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode(NULL,NULL,(yyvsp[(1) - (1)].nd_obj).name); ;}
    break;

  case 35:
#line 168 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(3) - (4)].nd_obj).nd, NULL, (yyvsp[(1) - (4)].nd_obj).name); ;}
    break;

  case 36:
#line 169 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(3) - (7)].nd_obj).nd, (yyvsp[(6) - (7)].nd_obj).nd, (yyvsp[(1) - (7)].nd_obj).name); ;}
    break;

  case 37:
#line 172 "./src/compiler.y"
    { (yyval.nd_obj).nd = (yyvsp[(1) - (1)].nd_obj).nd; ;}
    break;

  case 38:
#line 173 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj).nd, "VarExprList"); ;}
    break;

  case 39:
#line 176 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd,(yyvsp[(3) - (3)].nd_obj).nd, "="); ;}
    break;

  case 40:
#line 179 "./src/compiler.y"
    { (yyval.nd_obj).nd = (yyvsp[(1) - (1)].nd_obj).nd; ;}
    break;

  case 41:
#line 180 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, "StrExpr"); ;}
    break;

  case 42:
#line 183 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(3) - (4)].nd_obj).nd, NULL, "READ"); ;}
    break;

  case 43:
#line 186 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(3) - (4)].nd_obj).nd, NULL, "WRITE"); ;}
    break;

  case 44:
#line 187 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(4) - (6)].nd_obj).nd, NULL, "WRITE"); ;}
    break;

  case 45:
#line 190 "./src/compiler.y"
    { (yyval.nd_obj).nd = NULL; ;}
    break;

  case 46:
#line 191 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(3) - (4)].nd_obj).nd, NULL, "ELSE"); ;}
    break;

  case 47:
#line 194 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(3) - (8)].nd_obj).nd, mknode((yyvsp[(6) - (8)].nd_obj).nd, (yyvsp[(8) - (8)].nd_obj).nd, " "), "IF"); ;}
    break;

  case 48:
#line 197 "./src/compiler.y"
    { (yyval.nd_obj).nd = NULL; ;}
    break;

  case 49:
#line 198 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "Forcond1"); ;}
    break;

  case 50:
#line 201 "./src/compiler.y"
    { (yyval.nd_obj).nd = NULL; ;}
    break;

  case 51:
#line 202 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "Forcond2"); ;}
    break;

  case 52:
#line 203 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "Forcond2"); ;}
    break;

  case 53:
#line 206 "./src/compiler.y"
    { (yyval.nd_obj).nd = NULL; ;}
    break;

  case 54:
#line 207 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "Forcond3"); ;}
    break;

  case 55:
#line 208 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "Forcond3"); ;}
    break;

  case 56:
#line 213 "./src/compiler.y"
    { 
		(yyval.nd_obj).nd = mknode((yyvsp[(3) - (11)].nd_obj).nd, mknode((yyvsp[(5) - (11)].nd_obj).nd, mknode((yyvsp[(7) - (11)].nd_obj).nd, mknode((yyvsp[(10) - (11)].nd_obj).nd, NULL, " "), " "), " "), "FOR"); 
	;}
    break;

  case 57:
#line 219 "./src/compiler.y"
    { 
			(yyval.nd_obj).nd = mknode((yyvsp[(3) - (7)].nd_obj).nd, mknode((yyvsp[(6) - (7)].nd_obj).nd, NULL, " "), "WHILE"); 
		;}
    break;

  case 58:
#line 224 "./src/compiler.y"
    { (yyval.nd_obj).nd = (yyvsp[(1) - (2)].nd_obj).nd; ;}
    break;

  case 59:
#line 225 "./src/compiler.y"
    { (yyval.nd_obj).nd = (yyvsp[(1) - (2)].nd_obj).nd; ;}
    break;

  case 60:
#line 226 "./src/compiler.y"
    { (yyval.nd_obj).nd = (yyvsp[(1) - (2)].nd_obj).nd; ;}
    break;

  case 61:
#line 227 "./src/compiler.y"
    { (yyval.nd_obj).nd = (yyvsp[(1) - (1)].nd_obj).nd; ;}
    break;

  case 62:
#line 228 "./src/compiler.y"
    { (yyval.nd_obj).nd = (yyvsp[(1) - (1)].nd_obj).nd; ;}
    break;

  case 63:
#line 229 "./src/compiler.y"
    { (yyval.nd_obj).nd = (yyvsp[(1) - (1)].nd_obj).nd; ;}
    break;

  case 64:
#line 230 "./src/compiler.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "BREAK"); ;}
    break;

  case 65:
#line 233 "./src/compiler.y"
    { (yyval.nd_obj).nd = NULL; ;}
    break;

  case 66:
#line 235 "./src/compiler.y"
    { 
				(yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, "StmtList"); 
				// preorder($1.nd); 
				// cout<<"\n";
			;}
    break;


/* Line 1267 of yacc.c.  */
#line 1911 "./bin/parser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 241 "./src/compiler.y"


string removeExtension(string fileName) {
	
    size_t dotPos = fileName.find_last_of('.');
    if (dotPos != std::string::npos) {
        return fileName.substr(0, dotPos);
    } else {
        // No dot found, return the original file name
        return fileName;
    }
}

class MIPSCodeGenerator {
public:

    void generateMIPS(node* root, const char* inputFileName) {

        if(root == nullptr) return;

		if(root->data == "Programme"){

			gvarMIPS += "\t.file\t1 \""+string(inputFileName)+"\""+"\n";
			gvarMIPS += "\t.section .mdebug.abi32\n\t.previous\n\t.nan\tlegacy\n\t.module fp=xx\n\t.module nooddspreg\n\t.abicalls\n\t.text\n";

			generateGlobalDeclMIPS(root->l);

			if(root->r){
				genrateStmtListMIPS(root->r);
			} //

			if(mainStartMIPS == ""){

				mainStartMIPS+= "\t.text\n"
				"\t.align\t2\n"
				"\t.globl\tmain\n"
				"\t.set\tnomips16\n"
				"\t.set\tnomicromips\n"
				"\t.ent\tmain\n"
				"\t.type\tmain, @function\n"
				"main:\n"
				"\t.frame\t$fp,8,$31\t\t# vars= 0, regs= 1/0, args= 0, gp= 0\n"
				"\t.mask\t0x40000000,-4\n"
				"\t.fmask\t0x00000000,0\n"
				"\t.set\tnoreorder\n"
				"\t.set\tnomacro\n"
				"\taddiu\t$sp,$sp,-8\n"
				"\tsw\t$fp,4($sp)\n"
				"\tmove\t$fp,$sp\n";

			} //

			if(mainEndMIPS == ""){

				mainEndMIPS += "\tmove\t$2,$0\n"
				"\tmove\t$sp,$fp\n"
				"\tlw\t$fp,4($sp)\n"
				"\taddiu\t$sp,$sp,8\n"
				"\tjr\t$31\n"
				"\tnop\n\n"
				"\t.set\tmacro\n"
				"\t.set\treorder\n"
				"\t.end\tmain\n"
				"\t.size\tmain, .-main\n"
				"\t.ident\t\"GCC: (Ubuntu 10.3.0-1ubuntu1) 10.3.0\"\n"
				"\t.section\t.note.GNU-stack,\"\",@progbits\n";

			} //
		} else {
			cout<<"---- Syntax error in input programme ----\n";
		}
    }

private:
	int gvarLabel = 0, temp = 0, forLabel = 2, ifLabel = 2;
	unordered_map<int,bool> regAvailability = {
		{3, true},
		{4, true},
		{5, true},
		{6, true},
		{7, true},
		{8, true},
		{9, true},
		{10, true},
		{11, true},
		{12, true},
		{13, true},
		{14, true},
		{15, true},
		{16, true},
		{17, true},
		{18, true},
		{19, true},
		{20, true},
	}; // 

	void generateGlobalDeclMIPS(node* root) {

		if (root == nullptr) return;

		// Traverse the left subtree to process the first global declaration
		// currently at GlobalDeclSec node
		// one node left gives us GlobalDeclList

		// if GlobalDeclList is NULL then just return cause there are no global declarations
		if(root->l == nullptr) return;

		// The following nodes can't be null (cause of the way we declared grammer)
		// one node left to GlobalDeclList gives us first GlobalDecl
		// one node right to GlobalDecl gives us the integer declarations
		// if there are more than one inteneger declarations then root->l->l->r would be " "
		// else it would be name of first declaraed variable
		if(root->l->l->r->data == " "){
			generateGVarMIPS(true, root->l->l->r->l);
			node * temp = root->l->l->r->r;
			while(temp){
				if(temp->data == " ") {
					generateGVarMIPS(false, temp->l);
					temp = temp->r;
				} else {
					generateGVarMIPS(false, temp);
					break;
				} // 
			} // 
		} else generateGVarMIPS(true, root->l->l->r);

		// Now we are done with the first GlobalDecl, the remaining global declaration doesn't need any speacial attention
		node *temp = root->l->r;
		while(temp){

			// We are at GDecList node now, one node left is GDecl
			node *temp1 = temp->l->r;
			while(temp1){
				if(temp1->data == " ") {
					generateGVarMIPS(false, temp1->l);
					temp1 = temp1->r;
				} else {
					generateGVarMIPS(false, temp1);
					break;
				} //
			} //

			temp = temp->r;
		} 
	} // 

	void generateGVarMIPS(bool first, node *varNode) {
		if(first){
			if(varNode->l== NULL && varNode->r == NULL){

				// Normal intege or float variable
				string varName = varNode->data;

				gvarMIPS += "\t.globl\t" + varName + "\n"
				"\t.section\t.bss,\"aw\",@nobits\n"
				"\t.align\t2\n"
				"\t.type\t" + varName + ", @object\n"
				"\t.size\t" + varName + ", 4\n" +
				varName + ":\n"
				"\t.space\t4\n";

			} else if (varNode->r == NULL){

				// 1D array
				string varName = varNode->data;
				string size = to_string(4*varNode->l->iVal);

				gvarMIPS += "\t.globl\t" + varName + "\n"
				"\t.section\t.bss,\"aw\",@nobits\n"
				"\t.align\t2\n"
				"\t.type\t" + varName + ", @object\n"
				"\t.size\t" + varName + ", " + size + "\n" +
				varName + ":\n"
				"\t.space\t"+ size +"\n";
			} else {

				// 2D array
				string varName = varNode->data;
				string size = to_string(4*varNode->l->iVal*varNode->r->iVal);

				gvarMIPS += "\t.globl\t" + varName + "\n"
				"\t.section\t.bss,\"aw\",@nobits\n"
				"\t.align\t2\n"
				"\t.type\t" + varName + ", @object\n"
				"\t.size\t" + varName + ", " + size + "\n" +
				varName + ":\n"
				"\t.space\t"+ size +"\n";
			} //

		} else{
			
			if(varNode->l== NULL && varNode->r == NULL){

				// Normal intege or float variable
				string varName = varNode->data;

				gvarMIPS += "\t.globl\t" + varName + "\n"
				"\t.align\t2\n"
				"\t.type\t" + varName + ", @object\n"
				"\t.size\t" + varName + ", 4\n" +
				varName + ":\n"
				"\t.space\t4\n";

			} else if (varNode->r == NULL){

				// 1D array
				string varName = varNode->data;
				string size = to_string(4*varNode->l->iVal);

				gvarMIPS += "\t.globl\t" + varName + "\n"
				"\t.align\t2\n"
				"\t.type\t" + varName + ", @object\n"
				"\t.size\t" + varName + ", " + size + "\n" +
				varName + ":\n"
				"\t.space\t"+size+"\n";
			} else {

				// 2D array
				string varName = varNode->data;
				string size = to_string(4*varNode->l->iVal*varNode->r->iVal);

				gvarMIPS += "\t.globl\t" + varName + "\n"
				"\t.align\t2\n"
				"\t.type\t" + varName + ", @object\n"
				"\t.size\t" + varName + ", " + size + "\n" +
				varName + ":\n"
				"\t.space\t"+size+"\n";
			} //
		}
	} // 

	void genrateStmtListMIPS(node *rt) {

		if(rt == nullptr) return;

		if(rt->l->data == "WRITE"){

			if(gvarLabel == 0) {
				gvarMIPS += "\t.rdata\n"
				"\t.align\t2\n"
				"$LC"+to_string(gvarLabel++)+":\n"   // label name variable
				"\t.ascii\t\"" + "%d" + "\\000\"\n";
			} // 

			if(mainStartMIPS == ""){

				mainStartMIPS+= "\t.text\n"
				"\t.align\t2\n"
				"\t.globl\tmain\n"
				"\t.set\tnomips16\n"
				"\t.set\tnomicromips\n"
				"\t.ent\tmain\n"
				"\t.type\tmain, @function\n"
				"main:\n"
				"\t.frame\t$fp,32,$31\t\t# vars= 0, regs= 1/0, args= 0, gp= 0\n"
				"\t.mask\t0xc0000000,-4\n"
				"\t.fmask\t0x00000000,0\n"
				"\t.set\tnoreorder\n"
				"\t.set\tnomacro\n"
				"\taddiu\t$sp,$sp,-32\n"
				"\tsw\t$31,28($sp)\n"
				"\tsw\t$fp,24($sp)\n"
				"\tmove\t$fp,$sp\n"
				"\tlui\t$28,%hi(__gnu_local_gp)\n"
				"\taddiu\t$28,$28,%lo(__gnu_local_gp)\n"
				"\t.cprestore\t16\n";

			} // 

			node* temp = rt->l->l;

			while(temp){

				regAvailability[4] = false;
				regAvailability[5] = false;

				int resultReg;

				if(temp->data == "ExprList")  resultReg = generateExprMIPS(temp->l);
				else resultReg = generateExprMIPS(temp);

				mainBodyMIPS += "\tmove\t$5,$"+to_string(resultReg)+"\n"
				"\tlui\t$2,%hi($LC0)\n"
				"\taddiu\t$4,$2,%lo($LC0)\n"
				"\tlw\t$2,%call16(printf)($28)\n"
				"\tmove\t$25,$2\n"
				"\t.reloc\t1f,R_MIPS_JALR,printf\n"
				"1:\tjalr\t$25\n"
				"\tnop\n\n"
				"\tlw\t$28,16($fp)\n";

				mainBodyMIPS += "\tli\t$4,10			# 0xa\n"
				"\tlw\t$2,%call16(putchar)($28)\n"
				"\tmove\t$25,$2\n"
				"\t.reloc\t1f,R_MIPS_JALR,putchar\n"
				"1:\tjalr\t$25\n"
				"\tnop\n\n"
				"\tlw\t$28,16($fp)\n";

				regAvailability[4] = true;
				regAvailability[5] = true;

				if(temp->data == "ExprList") temp = temp->r;
				else break;
			} // 

			if(mainEndMIPS == "") {

				mainEndMIPS += "\tmove\t$2,$0\n"
				"\tmove\t$sp,$fp\n"
				"\tlw\t$31,28($sp)\n"
				"\tlw\t$fp,24($sp)\n"
				"\taddiu\t$sp,$sp,32\n"
				"\tjr\t$31\n"
				"\tnop\n\n"
				"\t.set\tmacro\n"
				"\t.set\treorder\n"
				"\t.end\tmain\n"
				"\t.size\tmain, .-main\n"
				"\t.ident\t\"GCC: (Ubuntu 10.3.0-1ubuntu1) 10.3.0\"\n"
				"\t.section\t.note.GNU-stack,\"\",@progbits\n";
			} // 

		} else if(rt->l->data == "READ") {
			
			if(gvarLabel == 0) {
				gvarMIPS += "\t.rdata\n"
				"\t.align\t2\n"
				"$LC"+to_string(gvarLabel++)+":\n"   // label name variable
				"\t.ascii\t\"" + "%d" + "\\000\"\n";
			} // 

			if(mainStartMIPS == ""){

				mainStartMIPS+= "\t.text\n"
				"\t.align\t2\n"
				"\t.globl\tmain\n"
				"\t.set\tnomips16\n"
				"\t.set\tnomicromips\n"
				"\t.ent\tmain\n"
				"\t.type\tmain, @function\n"
				"main:\n"
				"\t.frame\t$fp,32,$31\t\t# vars= 0, regs= 1/0, args= 0, gp= 0\n"
				"\t.mask\t0xc0000000,-4\n"
				"\t.fmask\t0x00000000,0\n"
				"\t.set\tnoreorder\n"
				"\t.set\tnomacro\n"
				"\taddiu\t$sp,$sp,-32\n"
				"\tsw\t$31,28($sp)\n"
				"\tsw\t$fp,24($sp)\n"
				"\tmove\t$fp,$sp\n"
				"\tlui\t$28,%hi(__gnu_local_gp)\n"
				"\taddiu\t$28,$28,%lo(__gnu_local_gp)\n"
				"\t.cprestore\t16\n";

			} // 

			node* temp = rt->l->l;

			while(temp){

				regAvailability[4] = false;
				regAvailability[5] = false;

				int resultReg;

				if(temp->data == "VarExprList")  resultReg = generateExprMIPS(mknode(temp->l, NULL, "__isoc99_scanf"));
				else resultReg = generateExprMIPS(mknode(temp, NULL, "__isoc99_scanf"));

				mainBodyMIPS += "\tmove\t$5,$"+to_string(resultReg)+"\n"
				"\tlui\t$2,%hi($LC0)\n"
				"\taddiu\t$4,$2,%lo($LC0)\n"
				"\tlw\t$2,%call16(__isoc99_scanf)($28)\n"
				"\tmove\t$25,$2\n"
				"\t.reloc\t1f,R_MIPS_JALR,__isoc99_scanf\n"
				"1:\tjalr\t$25\n"
				"\tnop\n\n"
				"\tlw\t$28,16($fp)\n";

				regAvailability[4] = true;
				regAvailability[5] = true;

				if(temp->data == "VarExprList") temp = temp->r;
				else break;
			} // 

			if(mainEndMIPS == "") {

				mainEndMIPS += "\tmove\t$2,$0\n"
				"\tmove\t$sp,$fp\n"
				"\tlw\t$31,28($sp)\n"
				"\tlw\t$fp,24($sp)\n"
				"\taddiu\t$sp,$sp,32\n"
				"\tjr\t$31\n"
				"\tnop\n\n"
				"\t.set\tmacro\n"
				"\t.set\treorder\n"
				"\t.end\tmain\n"
				"\t.size\tmain, .-main\n"
				"\t.ident\t\"GCC: (Ubuntu 10.3.0-1ubuntu1) 10.3.0\"\n"
				"\t.section\t.note.GNU-stack,\"\",@progbits\n";
			} // 
		} else if(rt->l->data == "="){

			// Variable on LHS
			if(rt->l->l->l == NULL && rt->l->l->r == NULL){

				int resultReg = generateExprMIPS(rt->l->r);
				// Assuming $3 contains the result of the RHS expression
				mainBodyMIPS += "\tlui\t$2,%hi("+rt->l->l->data+")\n"
				"\tsw\t$"+to_string(resultReg)+",%lo("+rt->l->l->data+")($2)\n";

			} // 1D Array on LHS 
			else if (rt->l->l->r == NULL) {

				int indexExprResultReg, rHSExprResultReg;

				indexExprResultReg = generateExprMIPS(rt->l->l->l); 

				regAvailability[indexExprResultReg] = false;

				rHSExprResultReg = generateExprMIPS(rt->l->r); 

				mainBodyMIPS += "\tlui\t$2,%hi("+rt->l->l->data+")\n"
				"\taddiu\t$2,$2,%lo("+rt->l->l->data+")            # $2 contains address(a)\n"
				"\tsll\t$"+to_string(indexExprResultReg)+",$"+to_string(indexExprResultReg)+",2\n"
				"\taddu\t$2,$2,$"+to_string(indexExprResultReg)+"\n"
				"\tsw\t$"+to_string(rHSExprResultReg)+",0($2)\n";

				regAvailability[indexExprResultReg] = true;

			} else{
				cantHandle = true;
				cantHandleString = "2D array is used in the programme\n";
			} //
		} else if(rt->l->data == "FOR"){

			forLabel += 3;

			// For condition 1
			if(rt->l->l && rt->l->l->data == "Forcond1") genrateStmtListMIPS(rt->l->l);
			mainBodyMIPS += "\t.option\tpic0  # Assemble for position-independent code\n"
			"\tb\t$L"+to_string(forLabel-3)+"  # Branch to (loop check)\n"
			"\tnop\n\n"
			"\t.option\tpic2  # Assemble for absolute code\n"
			"$L"+to_string(forLabel-2)+":   # Loop start\n";
			"\tnop\n\n";

			// For loop body
			genrateStmtListMIPS(rt->l->r->r->r->l);

			// For condition 3
			if(rt->l->r->r->l && rt->l->r->r->l->data == "Forcond3"){
				if(rt->l->r->r->l->l->data == "=") genrateStmtListMIPS(rt->l->r->r->l);
				else generateExprMIPS(rt->l->r->r->l->l);
			} // 

			// For condition 2
			mainBodyMIPS += "$L"+to_string(forLabel-3)+": # Loop check\n";
			"\tnop\n\n";
			if(rt->l->r->l && rt->l->r->l->data == "Forcond2") {
				if(rt->l->r->l->l->data == "=") {
					genrateStmtListMIPS(rt->l->r->l);
					mainBodyMIPS += "\tbeq\t$0,$0,$L"+to_string(forLabel-2)+"\n";
					"\tnop\n\n";
				} else {
					int resultReg = generateExprMIPS(rt->l->r->l->l);
					mainBodyMIPS += "\tbne\t$"+to_string(resultReg)+",$0,$L"+to_string(forLabel-2)+"\n";
				} // 
			} // 
			mainBodyMIPS += "\tnop\n\n";
			mainBodyMIPS += "$L"+to_string(forLabel-1)+":\n";
			"\tnop\n\n";

		} else if(rt->l->data == "IF") {

			ifLabel += 2;

			// Confition MIPS
			int conditionResultReg = generateExprMIPS(rt->l->l);
			mainBodyMIPS += "\tbeq\t$"+to_string(conditionResultReg)+",$0,$LL"+to_string(ifLabel-2)+"\n"
			"\tnop\n\n";

			// If Body MIPS
			genrateStmtListMIPS(rt->l->r->l);
			mainBodyMIPS += "\t.option\tpic0\n"
			"\tb\t$LL"+to_string(ifLabel-1)+"\n"
			"\tnop\n\n"
			"\t.option\tpic2\n"
			"$LL"+to_string(ifLabel-2)+":\n";
			"\tnop\n\n";

			// Else body MIPS
			if(rt->l->r->r) genrateStmtListMIPS(rt->l->r->r->l);
			mainBodyMIPS += "$LL"+to_string(ifLabel-1)+":\n";
			"\tnop\n\n";

		} else if(rt->l->data == "BREAK"){
			mainBodyMIPS += "\tbeq\t$0,$0,$L"+to_string(forLabel-1)+"\n"
			"\tnop\n\n";
		}

		genrateStmtListMIPS(rt->r);
	} //

	int generateExprMIPS(node *rt) {

		if(rt == nullptr) return -2;

		int returnReg = -1;
		for(auto it = regAvailability.begin(); it!=regAvailability.end(); it++){
			if(it->second){
				returnReg = it->first;
				break;
			} // 
		}// 
		if(returnReg == -1){

			cantHandle = true;
			cantHandleString = "Register limit reacher";
			return -1;
		} //
		regAvailability[returnReg] = false;

		if(rt->data == "NUM" || rt->data == "FLOAT"){

			mainBodyMIPS += "\tli\t$"+to_string(returnReg)+","+to_string(rt->iVal)+"\n";

		} else if (rt->data == "VarExpr") {

			// Variable
			if(rt->l->l == NULL && rt->l->r == NULL){

				mainBodyMIPS += "\tlui\t$2,%hi("+rt->l->data+")\n"
				"\tlw\t$"+to_string(returnReg)+",%lo("+rt->l->data+")($2)\n";

			} // 1D Array
			else if(rt->l->r == NULL) {

				int indexExprResultReg = generateExprMIPS(rt->l->l); 

				mainBodyMIPS += "\tlui\t$2,%hi("+rt->l->data+")\n"
				"\taddiu\t$2,$2,%lo("+rt->l->data+")\n"
				"\tsll\t$"+to_string(indexExprResultReg)+",$"+to_string(indexExprResultReg)+",2\n"
				"\taddu\t$2,$2,$"+to_string(indexExprResultReg)+"\n"
				"\tlw\t$"+to_string(returnReg)+",0($2)\n";

			} else {

				cantHandle = true;
				cantHandleString = "2D array is used in programme\n";
			} //

		} else if (rt->data == "__isoc99_scanf"){

			// Variable
			if(rt->l->l == NULL && rt->l->r == NULL){

				mainBodyMIPS += "\tlui\t$"+to_string(returnReg)+",%hi("+rt->l->data+")\n"
				"\taddiu\t$"+to_string(returnReg)+",$"+to_string(returnReg)+",%lo("+rt->l->data+")\n";

			} // 1D Array
			else if(rt->l->r == NULL) {

				int indexExprResultReg = generateExprMIPS(rt->l->l); 
				mainBodyMIPS += "\tlui\t$"+to_string(returnReg)+",%hi("+rt->l->data+")\n"
				"\taddiu\t$"+to_string(returnReg)+",$"+to_string(returnReg)+",%lo("+rt->l->data+")\n"
				"\tsll\t$"+to_string(indexExprResultReg)+",$"+to_string(indexExprResultReg)+",2\n"
				"\taddu\t$"+to_string(returnReg)+",$"+to_string(returnReg)+",$"+to_string(indexExprResultReg)+"\n";

			} else {

				cantHandle = true;
				cantHandleString = "2D array is used in programme\n";
			} //

		} else if (rt->data == "+") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tadd\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";

		} else if (rt->data == "-") {
			
			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tsub\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";

		} else if (rt->data == "*") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tmul\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		} else if (rt->data == "/") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tdiv\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		} else if (rt->data == "%") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\trem\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		} else if (rt->data == "<") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tslt\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		} else if (rt->data == ">") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tsgt\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		}  else if (rt->data == "==") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tseq\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		}  else if (rt->data == ">=") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tsge\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		}  else if (rt->data == "<=") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tsle\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		}  else if (rt->data == "!=") {

			int lHSExprResultReg = generateExprMIPS(rt->l);
			regAvailability[lHSExprResultReg] = false;
			int rHSExprResultReg = generateExprMIPS(rt->r);
			regAvailability[lHSExprResultReg] = true;
			mainBodyMIPS += "\tsne\t$"+to_string(returnReg)+",$"+to_string(lHSExprResultReg)+",$"+to_string(rHSExprResultReg)+"\n";
			
		} else if (rt->data == "()") {
			regAvailability[returnReg] = true;
			returnReg = generateExprMIPS(rt->l);
		} else if (rt->data == "Pre Incr") {

			// Variable
			if(rt->l->l == NULL && rt->l->r == NULL){

				mainBodyMIPS += "\tlui\t$2,%hi("+rt->l->data+")\n"
				"\tlw\t$2,%lo("+rt->l->data+")($2)\n" // $2 = variable
				"\taddiu\t$"+to_string(returnReg)+",$2,1\n" // returnReg = variable + 1
				"\tlui\t$2,%hi("+rt->l->data+")\n"    
				"\tsw\t$"+to_string(returnReg)+",%lo("+rt->l->data+")($2)\n"; // save incremented value in memeory

			} // 1D Array
			else if(rt->l->r == NULL) {

				mainBodyMIPS += "\tlui\t$2,%hi("+rt->l->data+")\n"
				"\taddiu\t$2,$2,%lo("+rt->l->data+")\n"
				"\tlw\t$2,"+to_string(4*rt->l->l->iVal)+"($2)\n" // $2 = variable
				"\taddiu\t$"+to_string(returnReg)+",$2,1\n" // returnReg = variable + 1
				"\tlui\t$2,%hi("+rt->l->data+")\n"    
				"\taddiu\t$2,$2,%lo("+rt->l->data+")\n"
				"\tsw\t$"+to_string(returnReg)+","+to_string(4*rt->l->l->iVal)+"($2)\n";


			} else {
				cout<<"Reached here 4\n";

				cantHandle = true;
				cantHandleString = "2D array is used in programme\n";
			} //

		} else if (rt->data == "Post Incr") {
			
			// Variable
			if(rt->l->l == NULL && rt->l->r == NULL){

				mainBodyMIPS += "\tlui\t$" + to_string(returnReg) + ",%hi(" + rt->l->data + ")\n"
                "\tlw\t$" + to_string(returnReg) + ",%lo("+rt->l->data+")($" + to_string(returnReg) + ")\n" // returnReg = variable
				"\taddiu\t$2,$"+to_string(returnReg)+",1\n" // $2 = variable + 1 
				"\tlui\t$" + to_string(returnReg) + ",%hi("+rt->l->data+")\n"
                "\tsw\t$2,%lo("+rt->l->data+")($" + to_string(returnReg) + ")\n" // save incremented value in memory
				"\taddiu\t$"+to_string(returnReg)+",$2,-1\n"; // returnReg = variable

			} // 1D Array
			else if(rt->l->r == NULL) {

				int indexExprResultReg = generateExprMIPS(rt->l->l); 
				mainBodyMIPS += "\tlui\t$" + to_string(returnReg) + ",%hi(" + rt->l->data + ")\n"
                "\taddiu\t$" + to_string(returnReg) + ",$" + to_string(returnReg) + ",%lo(" + rt->l->data + ")\n"
				"\tlw\t$" + to_string(returnReg) + "," + to_string(4 * rt->l->l->iVal) + "($" + to_string(returnReg) + ")\n" // returnReg = variable
				"\taddiu\t$2,$" + to_string(returnReg) + ",1\n" // $2 = variable + 1
				"\tlui\t$" + to_string(returnReg) + ",%hi("+rt->l->data+")\n"
                "\taddiu\t$" + to_string(returnReg) + ",$" + to_string(returnReg) + ",%lo(" + rt->l->data + ")\n"
                "\tsw\t$2," + to_string(4 * rt->l->l->iVal) + "($" + to_string(returnReg) + ")\n" // save incremented value in memory
				"\taddiu\t$"+to_string(returnReg)+",$2,-1\n"; // returnReg = variable


			} else {

				cantHandle = true;
				cantHandleString = "2D array is used in programme\n";
			} //

		} // 

		regAvailability[returnReg] = true;
		return returnReg;
	} //
};

void insert(string id) {

  if(!lookUp(yytext)) {

        symbolTableNode newEntry;
        newEntry.dataType = type;
		newEntry.type = "Variable";
        newEntry.lineNo = lineNo;
		newEntry.m = 0;
		newEntry.n = 0;
        symbolTable[id] = newEntry;
    }
} // 

void insert(string id, int m) {

  if(!lookUp(yytext)) {

	symbolTableNode newEntry;
    newEntry.dataType = type;
	newEntry.type = "1D Array";
	newEntry.m = m;
	newEntry.n = 0;
    newEntry.lineNo = lineNo;
    symbolTable[id] = newEntry;
  }
}

void insert(string id, int m, int n) {

  if(!lookUp(yytext)) {

	symbolTableNode newEntry;
    newEntry.dataType = type;
	newEntry.type = "2D Array";
	newEntry.m = m;
	newEntry.n = n;
    newEntry.lineNo = lineNo;
    symbolTable[id] = newEntry;
  }
}

// return if id is already is there or not in symbol table
int lookUp(string id) {
    return symbolTable.count(id) > 0;
}

void insertType() {
	type = yytext;
}

struct node * mknode(struct node *l, struct node *r, string s){

    node * newNode = new struct node;
    newNode->l = l;
    newNode->r = r;
    newNode->data = s;

    return newNode;
}

struct node * mknode(struct node *l, struct node *r, string s, int iVal){

    node * newNode = new struct node;
    newNode->l = l;
    newNode->r = r;
    newNode->data = s;
	newNode->iVal = iVal;

    return newNode;
}

struct node * mknode(struct node *l, struct node *r, string s, float fVal){

    node * newNode = new struct node;
    newNode->l = l;
    newNode->r = r;
    newNode->data = s;
	newNode->fVal = fVal;

    return newNode;
}

void preorder(node* rt, int depth) {
    if (rt == nullptr) return;

		for (int i = 0; i < depth; ++i) {
			cout << "    ";
		}
		cout << rt->data << "\n";

    preorder(rt->l, depth + 1);  // Print left subtree
    preorder(rt->r, depth + 1);  // Print right subtree
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}

int main(int argc, char *argv[]) {

	if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");

    if (!inputFile) {
        std::cerr << "Error: Unable to open input file " << argv[1] << std::endl;
        return 1;
    }

    yyin = inputFile;

    yyparse();

	cout<<"\n\t\t\tSYMBOL TABLE \n";
	cout<<"\nID        DATATYPE         TYPE         LINE NUMBER\n";
	cout<<"_________________________________________________________________________\n\n";

	
	for(auto it = symbolTable.begin(); it != symbolTable.end(); it++) {

        cout<<it->first<<"\t"<<it->second.dataType<<"\t"<<it->second.type<<"\t"<<it->second.lineNo<<"\t"<<"("<<it->second.m<<","<<it->second.n<<")"<<"\n";
    }
    cout<<"\n";

    cout<<"\n\n";
	cout<<"\t\t\tSYNTAXT TREE PREORDER TRAVERSAL\n\n";
    preorder(root,0);

	MIPSCodeGenerator().generateMIPS(root, argv[1]);
	mips = gvarMIPS + mainStartMIPS + mainBodyMIPS + mainEndMIPS;

	// Output file for MIPS code
    std::ofstream outputFile(removeExtension(string(argv[1]))+".s");
	if(!cantHandle) {
		outputFile<<mips;
	} else{
		outputFile<<cantHandleString;
	}
	outputFile.close();

	fclose(inputFile);
	return 0;
}
