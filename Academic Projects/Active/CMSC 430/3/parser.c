/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 44 "parser.y"


#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>

#include <vector>
#include "values.h"
using namespace std;
#include "listing.h"
#include "symbols.h"

#include <cstring> // for strcpy, also to reduce the need to use std::string and update symbols.h

int yylex();
void yyerror(const char* message);
double extract_element(CharPtr list_name, double subscript);
double parameter_parser(const char* text); // function to parse parameters from the function header

Symbols<double> scalars; //from symbols.h
Symbols<double> paramSymbols;  // holds param1, param2, ...
Symbols<vector<double>*> lists;
double result;


#line 99 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_LITERAL = 3,                /* INT_LITERAL  */
  YYSYMBOL_REAL_LITERAL = 4,               /* REAL_LITERAL  */
  YYSYMBOL_HEX_LITERAL = 5,                /* HEX_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 6,               /* CHAR_LITERAL  */
  YYSYMBOL_RELOP = 7,                      /* RELOP  */
  YYSYMBOL_ADDOP = 8,                      /* ADDOP  */
  YYSYMBOL_ANDOP = 9,                      /* ANDOP  */
  YYSYMBOL_MULOP = 10,                     /* MULOP  */
  YYSYMBOL_MODOP = 11,                     /* MODOP  */
  YYSYMBOL_NEGOP = 12,                     /* NEGOP  */
  YYSYMBOL_EXPOP = 13,                     /* EXPOP  */
  YYSYMBOL_IDENTIFIER = 14,                /* IDENTIFIER  */
  YYSYMBOL_LEFT = 15,                      /* LEFT  */
  YYSYMBOL_RIGHT = 16,                     /* RIGHT  */
  YYSYMBOL_ARROW = 17,                     /* ARROW  */
  YYSYMBOL_OROP = 18,                      /* OROP  */
  YYSYMBOL_NOTOP = 19,                     /* NOTOP  */
  YYSYMBOL_WHEN = 20,                      /* WHEN  */
  YYSYMBOL_BEGIN_ = 21,                    /* BEGIN_  */
  YYSYMBOL_END = 22,                       /* END  */
  YYSYMBOL_FUNCTION = 23,                  /* FUNCTION  */
  YYSYMBOL_IS = 24,                        /* IS  */
  YYSYMBOL_LIST = 25,                      /* LIST  */
  YYSYMBOL_OF = 26,                        /* OF  */
  YYSYMBOL_RETURNS = 27,                   /* RETURNS  */
  YYSYMBOL_SWITCH = 28,                    /* SWITCH  */
  YYSYMBOL_CASE = 29,                      /* CASE  */
  YYSYMBOL_OTHERS = 30,                    /* OTHERS  */
  YYSYMBOL_ENDSWITCH = 31,                 /* ENDSWITCH  */
  YYSYMBOL_IF = 32,                        /* IF  */
  YYSYMBOL_THEN = 33,                      /* THEN  */
  YYSYMBOL_ELSE = 34,                      /* ELSE  */
  YYSYMBOL_ELSIF = 35,                     /* ELSIF  */
  YYSYMBOL_ENDIF = 36,                     /* ENDIF  */
  YYSYMBOL_FOLD = 37,                      /* FOLD  */
  YYSYMBOL_ENDFOLD = 38,                   /* ENDFOLD  */
  YYSYMBOL_CHARACTER = 39,                 /* CHARACTER  */
  YYSYMBOL_REAL = 40,                      /* REAL  */
  YYSYMBOL_INTEGER = 41,                   /* INTEGER  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* ':'  */
  YYSYMBOL_45_ = 45,                       /* '('  */
  YYSYMBOL_46_ = 46,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_function = 48,                  /* function  */
  YYSYMBOL_function_header = 49,           /* function_header  */
  YYSYMBOL_parameters = 50,                /* parameters  */
  YYSYMBOL_parameter = 51,                 /* parameter  */
  YYSYMBOL_optional_variable = 52,         /* optional_variable  */
  YYSYMBOL_variable = 53,                  /* variable  */
  YYSYMBOL_type = 54,                      /* type  */
  YYSYMBOL_body = 55,                      /* body  */
  YYSYMBOL_statement_ = 56,                /* statement_  */
  YYSYMBOL_statement = 57,                 /* statement  */
  YYSYMBOL_SWITCH_descent = 58,            /* SWITCH_descent  */
  YYSYMBOL_IF_descent = 59,                /* IF_descent  */
  YYSYMBOL_ELSIF_descent = 60,             /* ELSIF_descent  */
  YYSYMBOL_direction = 61,                 /* direction  */
  YYSYMBOL_operator = 62,                  /* operator  */
  YYSYMBOL_cases = 63,                     /* cases  */
  YYSYMBOL_case = 64,                      /* case  */
  YYSYMBOL_condition_list = 65,            /* condition_list  */
  YYSYMBOL_condition = 66,                 /* condition  */
  YYSYMBOL_relation = 67,                  /* relation  */
  YYSYMBOL_list = 68,                      /* list  */
  YYSYMBOL_expressions = 69,               /* expressions  */
  YYSYMBOL_expression = 70,                /* expression  */
  YYSYMBOL_term = 71,                      /* term  */
  YYSYMBOL_primary = 72                    /* primary  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   383

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,    46,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    42,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   109,   109,   112,   113,   116,   117,   117,   120,   123,
     124,   125,   126,   129,   130,   133,   134,   135,   138,   141,
     142,   143,   143,   146,   147,   148,   148,   149,   150,   154,
     155,   159,   162,   163,   164,   167,   167,   170,   170,   173,
     173,   176,   177,   181,   182,   183,   186,   187,   190,   191,
     192,   195,   196,   199,   200,   203,   204,   207,   208,   209,
     210,   211,   215,   216,   217,   218,   219,   220,   221,   222,
     223
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT_LITERAL",
  "REAL_LITERAL", "HEX_LITERAL", "CHAR_LITERAL", "RELOP", "ADDOP", "ANDOP",
  "MULOP", "MODOP", "NEGOP", "EXPOP", "IDENTIFIER", "LEFT", "RIGHT",
  "ARROW", "OROP", "NOTOP", "WHEN", "BEGIN_", "END", "FUNCTION", "IS",
  "LIST", "OF", "RETURNS", "SWITCH", "CASE", "OTHERS", "ENDSWITCH", "IF",
  "THEN", "ELSE", "ELSIF", "ENDIF", "FOLD", "ENDFOLD", "CHARACTER", "REAL",
  "INTEGER", "';'", "','", "':'", "'('", "')'", "$accept", "function",
  "function_header", "parameters", "parameter", "optional_variable",
  "variable", "type", "body", "statement_", "statement", "SWITCH_descent",
  "IF_descent", "ELSIF_descent", "direction", "operator", "cases", "case",
  "condition_list", "condition", "relation", "list", "expressions",
  "expression", "term", "primary", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-35)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      58,   -91,    -1,    17,    75,     9,   -91,    19,    36,    61,
      46,    77,    -3,   -91,   -91,   174,   103,    85,   -91,   -91,
      72,    72,     9,   120,   -91,   -91,   -91,   118,   108,   -91,
     -91,   -91,   -91,   309,   109,   309,    27,   309,   326,   117,
     309,   133,   121,   -91,   -91,   150,   149,   -91,   -91,   -91,
     134,   -91,    72,   279,   149,   309,   149,   -91,   338,   326,
      49,   -91,   -91,   172,   106,   110,   -91,   -91,   116,    -2,
     -91,   139,   142,   -91,   309,   309,   309,   309,   309,   -91,
     162,   -91,     7,   -91,   149,   146,     2,   326,   326,   309,
     309,   164,    15,   -91,   -91,    50,   -91,   -91,   -91,   149,
     -91,   -91,   -91,   -91,    50,   -91,   -91,   -91,   -91,    30,
     150,   148,   176,   -91,    65,   -91,   309,   159,   -91,   309,
     160,   190,   192,   -91,   291,   167,   -32,   150,   -91,   150,
     -91,   279,   163,   175,   111,   184,   309,   -91,   169,   221,
     -91,    15,   242,   150,   -91,   -91,    65,   -91,   -91
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,     0,     0,     7,     1,     0,     0,     0,
       0,     0,     0,     6,    11,     0,     0,     0,     2,    10,
       0,     0,     0,     0,    16,    17,    15,     0,    21,    65,
      67,    68,    66,     0,    70,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    27,    23,    56,    61,     9,     8,
       0,     5,     0,     0,    63,     0,    64,    25,     0,     0,
       0,    45,    47,    50,     0,     0,    35,    36,     0,     0,
      30,     0,     0,    20,     0,     0,     0,     0,     0,     3,
       0,    13,     0,    46,    56,     0,     0,     0,     0,     0,
       0,     0,     0,    37,    38,     0,    62,    18,    19,    55,
      60,    57,    58,    59,     0,    69,    48,    43,    44,     0,
      49,     0,     0,    40,     0,    52,     0,     0,    14,     0,
       0,     0,     0,    39,     0,     0,     0,    54,    28,    24,
      42,     0,     0,    34,     0,     0,     0,    51,     0,     0,
      33,     0,     0,    53,    41,    29,     0,    31,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,   -91,   -91,   195,   -91,   209,    42,   -91,   -90,
     -41,   -91,   -91,   -68,   -91,   -91,   -91,   107,   -37,   -51,
     165,   124,   -91,   -33,    83,    96
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,    12,    13,     9,    10,    27,    18,    41,
      42,    43,    44,   125,    68,    95,   112,   113,    60,    61,
      62,   117,   126,    45,    46,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      72,    65,   114,    63,    64,    63,    74,    69,    85,    90,
      74,   136,    81,     5,   137,    74,    28,     6,    29,    30,
      31,    32,    82,    11,    21,    63,    86,    33,    57,    34,
      29,    30,    31,    32,    35,    36,   107,   108,    74,    33,
      22,    34,   139,    37,    96,   142,    58,    38,    96,   -22,
     -22,   146,    39,   105,    63,    63,   109,   110,    87,     1,
      40,    14,    49,    50,   115,   140,    70,    88,    29,    30,
      31,    32,    59,    72,   119,     8,     7,    33,   148,    34,
      15,     2,    16,   127,    35,    36,   129,   134,    19,     8,
     138,    63,    89,    37,    80,   116,   -12,    38,    72,   -34,
     124,    72,    39,   143,    28,    72,    29,    30,    31,    32,
      40,    24,    25,    26,    74,    33,    54,    34,    56,    87,
      87,    20,    35,    36,    93,   -22,    94,    48,    88,    88,
      91,    37,    66,    67,    70,    38,    29,    30,    31,    32,
      39,    84,    53,    92,   141,    33,    52,    34,    40,   120,
     -30,   121,    35,    36,    55,    71,    75,    99,    74,    76,
      77,    37,    78,    73,    28,    38,    29,    30,    31,    32,
      39,   100,   101,   102,   103,    33,    79,    34,    40,    90,
      74,    97,    35,    36,    98,    28,   104,    29,    30,    31,
      32,    37,   106,   111,   -22,    38,    33,   128,    34,    23,
      39,   135,   130,    35,    36,   111,   122,   131,    40,   132,
     124,   144,    37,    24,    25,    26,    38,    51,    17,   123,
     -22,    39,    70,    83,    29,    30,    31,    32,   118,    40,
       0,     0,     0,    33,     0,    34,     0,     0,     0,     0,
      35,    36,     0,    70,     0,    29,    30,    31,    32,    37,
       0,     0,   145,    38,    33,     0,    34,     0,    39,     0,
       0,    35,    36,     0,     0,     0,    40,     0,     0,     0,
      37,     0,     0,     0,    38,     0,     0,     0,   147,    39,
      70,     0,    29,    30,    31,    32,     0,    40,     0,     0,
       0,    33,   133,    34,    29,    30,    31,    32,    35,    36,
       0,     0,     0,    33,     0,    34,     0,    37,     0,     0,
      58,    38,    29,    30,    31,    32,    39,     0,     0,     0,
       0,    33,     0,    34,    40,     0,     0,     0,    35,    29,
      30,    31,    32,     0,     0,     0,    59,     0,    33,     0,
      34,    29,    30,    31,    32,    58,     0,     0,     0,     0,
      33,     0,    34,     0,    40,     0,     0,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    59,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59
};

static const yytype_int16 yycheck[] =
{
      41,    38,    92,    36,    37,    38,     8,    40,    59,     7,
       8,    43,    53,    14,    46,     8,     1,     0,     3,     4,
       5,     6,    55,    14,    27,    58,    59,    12,     1,    14,
       3,     4,     5,     6,    19,    20,    87,    88,     8,    12,
      43,    14,   132,    28,    46,   135,    19,    32,    46,    34,
      35,   141,    37,    46,    87,    88,    89,    90,     9,     1,
      45,    42,    20,    21,    14,   133,     1,    18,     3,     4,
       5,     6,    45,   114,    44,    14,     1,    12,   146,    14,
      44,    23,    21,   116,    19,    20,   119,   124,    42,    14,
     131,   124,    43,    28,    52,    45,    21,    32,   139,    34,
      35,   142,    37,   136,     1,   146,     3,     4,     5,     6,
      45,    39,    40,    41,     8,    12,    33,    14,    35,     9,
       9,    44,    19,    20,     8,    22,    10,    42,    18,    18,
      24,    28,    15,    16,     1,    32,     3,     4,     5,     6,
      37,    58,    24,    33,    33,    12,    26,    14,    45,     1,
      42,     3,    19,    20,    45,    22,     7,    74,     8,    10,
      11,    28,    13,    42,     1,    32,     3,     4,     5,     6,
      37,    75,    76,    77,    78,    12,    42,    14,    45,     7,
       8,    42,    19,    20,    42,     1,    24,     3,     4,     5,
       6,    28,    46,    29,    31,    32,    12,    38,    14,    25,
      37,    34,    42,    19,    20,    29,    30,    17,    45,    17,
      35,    42,    28,    39,    40,    41,    32,    22,     9,   112,
      36,    37,     1,    58,     3,     4,     5,     6,   104,    45,
      -1,    -1,    -1,    12,    -1,    14,    -1,    -1,    -1,    -1,
      19,    20,    -1,     1,    -1,     3,     4,     5,     6,    28,
      -1,    -1,    31,    32,    12,    -1,    14,    -1,    37,    -1,
      -1,    19,    20,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    37,
       1,    -1,     3,     4,     5,     6,    -1,    45,    -1,    -1,
      -1,    12,     1,    14,     3,     4,     5,     6,    19,    20,
      -1,    -1,    -1,    12,    -1,    14,    -1,    28,    -1,    -1,
      19,    32,     3,     4,     5,     6,    37,    -1,    -1,    -1,
      -1,    12,    -1,    14,    45,    -1,    -1,    -1,    19,     3,
       4,     5,     6,    -1,    -1,    -1,    45,    -1,    12,    -1,
      14,     3,     4,     5,     6,    19,    -1,    -1,    -1,    -1,
      12,    -1,    14,    -1,    45,    -1,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    23,    48,    49,    14,     0,     1,    14,    52,
      53,    14,    50,    51,    42,    44,    21,    53,    55,    42,
      44,    27,    43,    25,    39,    40,    41,    54,     1,     3,
       4,     5,     6,    12,    14,    19,    20,    28,    32,    37,
      45,    56,    57,    58,    59,    70,    71,    72,    42,    54,
      54,    51,    26,    24,    71,    45,    71,     1,    19,    45,
      65,    66,    67,    70,    70,    65,    15,    16,    61,    70,
       1,    22,    57,    42,     8,     7,    10,    11,    13,    42,
      54,    57,    70,    67,    71,    66,    70,     9,    18,    43,
       7,    24,    33,     8,    10,    62,    46,    42,    42,    71,
      72,    72,    72,    72,    24,    46,    46,    66,    66,    70,
      70,    29,    63,    64,    56,    14,    45,    68,    68,    44,
       1,     3,    30,    64,    35,    60,    69,    70,    38,    70,
      42,    17,    17,     1,    65,    34,    43,    46,    57,    56,
      60,    33,    56,    70,    42,    31,    56,    36,    60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    51,    52,
      52,    52,    52,    53,    53,    54,    54,    54,    55,    56,
      56,    56,    56,    57,    57,    57,    57,    57,    57,    58,
      58,    59,    60,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    65,    66,    66,    67,    67,
      67,    68,    68,    69,    69,    70,    70,    71,    71,    71,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     6,     1,     3,     1,     0,     3,     3,
       2,     2,     0,     5,     7,     1,     1,     1,     4,     3,
       2,     1,     0,     1,     6,     2,     1,     1,     5,     8,
       1,     8,     5,     3,     0,     1,     1,     1,     1,     2,
       1,     5,     3,     3,     3,     1,     2,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     1,     3,     2,     2,     1,     1,     1,     1,     4,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* function: function_header optional_variable body  */
#line 109 "parser.y"
                                                {result = (yyvsp[0].dbl);}
#line 1571 "parser.tab.c"
    break;

  case 4: /* function_header: error  */
#line 113 "parser.y"
                      {appendError(SYNTAX, "Function header error");}
#line 1577 "parser.tab.c"
    break;

  case 8: /* parameter: IDENTIFIER ':' type  */
#line 120 "parser.y"
                            {parameter_parser((yyvsp[-2].iden));}
#line 1583 "parser.tab.c"
    break;

  case 13: /* variable: IDENTIFIER ':' type IS statement  */
#line 129 "parser.y"
                                         {scalars.insert((yyvsp[-4].iden), (yyvsp[0].dbl)); }
#line 1589 "parser.tab.c"
    break;

  case 14: /* variable: IDENTIFIER ':' LIST OF type IS list  */
#line 130 "parser.y"
                                            {lists.insert((yyvsp[-6].iden), (yyvsp[0].list));}
#line 1595 "parser.tab.c"
    break;

  case 18: /* body: BEGIN_ statement_ END ';'  */
#line 138 "parser.y"
                                  {(yyval.dbl) = (yyvsp[-2].dbl);}
#line 1601 "parser.tab.c"
    break;

  case 19: /* statement_: statement_ statement ';'  */
#line 141 "parser.y"
                                 {(yyval.dbl) = (yyvsp[-2].dbl);}
#line 1607 "parser.tab.c"
    break;

  case 21: /* statement_: error  */
#line 143 "parser.y"
              {(yyval.dbl) = NAN;}
#line 1613 "parser.tab.c"
    break;

  case 22: /* statement_: %empty  */
#line 143 "parser.y"
                                   {(yyval.dbl) = 0;}
#line 1619 "parser.tab.c"
    break;

  case 24: /* statement: WHEN condition_list ',' expression ':' expression  */
#line 147 "parser.y"
                                                          {(yyval.dbl) = (yyvsp[-4].dbl) ? (yyvsp[-2].dbl) : (yyvsp[0].dbl);}
#line 1625 "parser.tab.c"
    break;

  case 25: /* statement: WHEN error  */
#line 148 "parser.y"
               {(yyval.dbl)=0;}
#line 1631 "parser.tab.c"
    break;

  case 28: /* statement: FOLD direction operator list ENDFOLD  */
#line 150 "parser.y"
                                             {(yyval.dbl) = evaluateFold((yyvsp[-3].value), (yyvsp[-2].oper), (yyvsp[-1].list));}
#line 1637 "parser.tab.c"
    break;

  case 29: /* SWITCH_descent: SWITCH expression IS cases OTHERS ARROW statement_ ENDSWITCH  */
#line 154 "parser.y"
                                                                     {(yyval.dbl) = !isnan((yyvsp[-4].dbl)) ? (yyvsp[-4].dbl) : (yyvsp[-1].dbl);}
#line 1643 "parser.tab.c"
    break;

  case 30: /* SWITCH_descent: error  */
#line 155 "parser.y"
                {(yyval.dbl) = NAN;}
#line 1649 "parser.tab.c"
    break;

  case 31: /* IF_descent: IF condition_list THEN statement_ ELSIF_descent ELSE statement_ ENDIF  */
#line 159 "parser.y"
                                                                              { (yyval.dbl) = (yyvsp[-6].dbl) ? (yyvsp[-4].dbl) : ((yyvsp[-3].dbl) != -1 ? (yyvsp[-3].dbl) : (yyvsp[-1].dbl)); }
#line 1655 "parser.tab.c"
    break;

  case 32: /* ELSIF_descent: ELSIF condition_list THEN statement_ ELSIF_descent  */
#line 162 "parser.y"
                                                           {(yyval.dbl) = (yyvsp[-3].dbl) ? (yyvsp[-1].dbl) : (yyvsp[0].dbl);}
#line 1661 "parser.tab.c"
    break;

  case 33: /* ELSIF_descent: ELSIF error ELSIF_descent  */
#line 163 "parser.y"
                                  { (yyval.dbl) = (yyvsp[0].dbl); }
#line 1667 "parser.tab.c"
    break;

  case 34: /* ELSIF_descent: %empty  */
#line 164 "parser.y"
               {(yyval.dbl) = -1;}
#line 1673 "parser.tab.c"
    break;

  case 35: /* direction: LEFT  */
#line 167 "parser.y"
         { (yyval.value) = 1; }
#line 1679 "parser.tab.c"
    break;

  case 36: /* direction: RIGHT  */
#line 167 "parser.y"
                             { (yyval.value) = 0; }
#line 1685 "parser.tab.c"
    break;

  case 41: /* case: CASE INT_LITERAL ARROW statement ';'  */
#line 176 "parser.y"
                                             {(yyval.dbl) = (yyvsp[(-2) - (5)].value) == (yyvsp[-3].value) ? (yyvsp[-1].dbl) : NAN;}
#line 1691 "parser.tab.c"
    break;

  case 42: /* case: CASE error ';'  */
#line 177 "parser.y"
                       {(yyval.dbl)=0;}
#line 1697 "parser.tab.c"
    break;

  case 43: /* condition_list: condition_list ANDOP condition  */
#line 181 "parser.y"
                                       {(yyval.dbl) = (yyvsp[-2].dbl) && (yyvsp[0].dbl);}
#line 1703 "parser.tab.c"
    break;

  case 44: /* condition_list: condition_list OROP condition  */
#line 182 "parser.y"
                                      {(yyval.dbl) = (yyvsp[-2].dbl) || (yyvsp[0].dbl);}
#line 1709 "parser.tab.c"
    break;

  case 46: /* condition: NOTOP relation  */
#line 186 "parser.y"
                       {(yyval.dbl) = !(yyvsp[0].dbl);}
#line 1715 "parser.tab.c"
    break;

  case 48: /* relation: '(' condition ')'  */
#line 190 "parser.y"
                          {(yyval.dbl) = (yyvsp[-1].dbl);}
#line 1721 "parser.tab.c"
    break;

  case 49: /* relation: expression RELOP expression  */
#line 191 "parser.y"
                                    {(yyval.dbl) = evaluateRelational((yyvsp[-2].dbl), (yyvsp[-1].oper), (yyvsp[0].dbl));}
#line 1727 "parser.tab.c"
    break;

  case 51: /* list: '(' expressions ')'  */
#line 195 "parser.y"
                            {(yyval.list) = (yyvsp[-1].list);}
#line 1733 "parser.tab.c"
    break;

  case 52: /* list: IDENTIFIER  */
#line 196 "parser.y"
                   {vector<double>* ptr = nullptr; if (lists.find((yyvsp[0].iden), ptr)) (yyval.list) = ptr; else { appendError(UNDECLARED, (yyvsp[0].iden)); (yyval.list) = nullptr; }}
#line 1739 "parser.tab.c"
    break;

  case 53: /* expressions: expressions ',' expression  */
#line 199 "parser.y"
                                    {(yyvsp[-2].list)->push_back((yyvsp[0].dbl)); (yyval.list) = (yyvsp[-2].list);}
#line 1745 "parser.tab.c"
    break;

  case 54: /* expressions: expression  */
#line 200 "parser.y"
                   {(yyval.list) = new vector<double>(); (yyval.list)->push_back((yyvsp[0].dbl));}
#line 1751 "parser.tab.c"
    break;

  case 55: /* expression: expression ADDOP term  */
#line 203 "parser.y"
                              {(yyval.dbl) = evaluateArithmetic((yyvsp[-2].dbl), (yyvsp[-1].oper), (yyvsp[0].dbl));}
#line 1757 "parser.tab.c"
    break;

  case 57: /* term: term MULOP primary  */
#line 207 "parser.y"
                           {(yyval.dbl) = evaluateArithmetic((yyvsp[-2].dbl), (yyvsp[-1].oper), (yyvsp[0].dbl));}
#line 1763 "parser.tab.c"
    break;

  case 58: /* term: term MODOP primary  */
#line 208 "parser.y"
                           {(yyval.dbl) = evaluateArithmetic((yyvsp[-2].dbl), (yyvsp[-1].oper), (yyvsp[0].dbl));}
#line 1769 "parser.tab.c"
    break;

  case 59: /* term: term EXPOP primary  */
#line 209 "parser.y"
                           {(yyval.dbl) = evaluateArithmetic((yyvsp[-2].dbl), (yyvsp[-1].oper), (yyvsp[0].dbl));}
#line 1775 "parser.tab.c"
    break;

  case 60: /* term: term RELOP primary  */
#line 210 "parser.y"
                       {(yyval.dbl) = evaluateRelational((yyvsp[-2].dbl), (yyvsp[-1].oper), (yyvsp[0].dbl));}
#line 1781 "parser.tab.c"
    break;

  case 62: /* primary: '(' expression ')'  */
#line 215 "parser.y"
                           {(yyval.dbl) = (yyvsp[-1].dbl);}
#line 1787 "parser.tab.c"
    break;

  case 63: /* primary: NEGOP term  */
#line 216 "parser.y"
                   {(yyval.dbl) = -(yyvsp[0].dbl);}
#line 1793 "parser.tab.c"
    break;

  case 64: /* primary: NOTOP term  */
#line 217 "parser.y"
                   {(yyval.dbl) = !(yyvsp[0].dbl);}
#line 1799 "parser.tab.c"
    break;

  case 65: /* primary: INT_LITERAL  */
#line 218 "parser.y"
                    { (yyval.dbl) = static_cast<double>((yyvsp[0].value)); }
#line 1805 "parser.tab.c"
    break;

  case 66: /* primary: CHAR_LITERAL  */
#line 219 "parser.y"
                     { (yyval.dbl) = static_cast<double>((yyvsp[0].value)); }
#line 1811 "parser.tab.c"
    break;

  case 67: /* primary: REAL_LITERAL  */
#line 220 "parser.y"
                     { (yyval.dbl) = static_cast<double>((yyvsp[0].value)); }
#line 1817 "parser.tab.c"
    break;

  case 68: /* primary: HEX_LITERAL  */
#line 221 "parser.y"
                    { (yyval.dbl) = static_cast<double>((yyvsp[0].value)); }
#line 1823 "parser.tab.c"
    break;

  case 69: /* primary: IDENTIFIER '(' expression ')'  */
#line 222 "parser.y"
                                      {(yyval.dbl) = extract_element((yyvsp[-3].iden), (yyvsp[-1].dbl)); }
#line 1829 "parser.tab.c"
    break;

  case 70: /* primary: IDENTIFIER  */
#line 223 "parser.y"
                   {if (!scalars.find((yyvsp[0].iden), (yyval.dbl))) appendError(UNDECLARED, (yyvsp[0].iden));}
#line 1835 "parser.tab.c"
    break;


#line 1839 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 226 "parser.y"


void yyerror(const char* message) {
	appendError(SYNTAX, message);
}

double extract_element(CharPtr list_name, double subscript) {
	vector<double>* list; 
	if (lists.find(list_name, list))
		return (*list)[subscript];
	appendError(UNDECLARED, list_name);
	return NAN;
}

//helper for parameter parsing
double parameter_parser(const char* declaredName) {
	// This function is used to parse parameters from the function header
	// It creates a unique parameter name (param1, param2, ...) and links it
	static int paramIndex = 1;
	double value = 0;

	std::string paramKey = "param" + std::to_string(paramIndex++);
	
	// Debugging output
	//std::cout << "Parameterkey " << paramKey <<std::endl;

	char* paramKeyC = strdup(paramKey.c_str());
	char* declaredC = strdup(declaredName);

		if (paramSymbols.find(paramKeyC, value)) {
			scalars.insert(declaredC, value);  // link to true name
			//std::cout << "Parameter inserted: " << declaredC << " value: " << value << std::endl;
		//debugging output
		} //should skip if no parameter is found
		else {
			appendError(UNDECLARED, declaredC);
			value = NAN; // set value to NaN if parameter is not found
		}
	
	// Debugging output
	//std::cout << "parameter value linked to variable: " << value << std::endl;

		free(paramKeyC);
		free(declaredC);
		return value;
}



int main(int argc, char *argv[]) {



	//added script to handle command line arguments for parameters
	if (argc > 1) {
		double* params = new double[argc - 1];

		for (int i = 1; i < argc; i++) {
			double value = atof(argv[i]);
			std::string name = "param" + std::to_string(i);
			char* buffer = new char[name.length() + 1];
			strcpy(buffer, name.c_str());
			paramSymbols.insert(buffer, value);
			//debugging output
			//std::cout << "Parameter inserted: " << buffer << " value: " << value << std::endl;
			delete[] buffer;
		}

		delete[] params;
	}

	
	firstLine();
	yyparse();
	if (lastLine() == 0)
		cout << "Result = " << result << endl;
	return 0;
} 
