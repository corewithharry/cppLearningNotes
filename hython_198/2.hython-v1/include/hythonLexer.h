/** \file
 *  This C header file was generated by $ANTLR version 3.4
 *
 *     -  From the grammar source file : ./thirdpart/hython.g
 *     -                            On : 2020-08-27 22:58:31
 *     -                 for the lexer : hythonLexerLexer
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The lexer 
hythonLexer

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef phythonLexer, which is returned from a call to hythonLexerNew().
 *
 * As this is a generated lexer, it is unlikely you will call it 'manually'. However
 * the methods are provided anyway.
 *
 * The methods in phythonLexer are  as follows:
 *
 *  - 
 void
      phythonLexer->T__39(phythonLexer)
 *  - 
 void
      phythonLexer->T__40(phythonLexer)
 *  - 
 void
      phythonLexer->T__41(phythonLexer)
 *  - 
 void
      phythonLexer->T__42(phythonLexer)
 *  - 
 void
      phythonLexer->T__43(phythonLexer)
 *  - 
 void
      phythonLexer->MOD(phythonLexer)
 *  - 
 void
      phythonLexer->DIV(phythonLexer)
 *  - 
 void
      phythonLexer->DO(phythonLexer)
 *  - 
 void
      phythonLexer->DOWHILE(phythonLexer)
 *  - 
 void
      phythonLexer->WHILE(phythonLexer)
 *  - 
 void
      phythonLexer->FOR(phythonLexer)
 *  - 
 void
      phythonLexer->PRINT(phythonLexer)
 *  - 
 void
      phythonLexer->IF(phythonLexer)
 *  - 
 void
      phythonLexer->ELSE(phythonLexer)
 *  - 
 void
      phythonLexer->OR(phythonLexer)
 *  - 
 void
      phythonLexer->AND(phythonLexer)
 *  - 
 void
      phythonLexer->GE(phythonLexer)
 *  - 
 void
      phythonLexer->NE(phythonLexer)
 *  - 
 void
      phythonLexer->LITTLE(phythonLexer)
 *  - 
 void
      phythonLexer->LE(phythonLexer)
 *  - 
 void
      phythonLexer->GT(phythonLexer)
 *  - 
 void
      phythonLexer->EQ(phythonLexer)
 *  - 
 void
      phythonLexer->PLUS(phythonLexer)
 *  - 
 void
      phythonLexer->MINUS(phythonLexer)
 *  - 
 void
      phythonLexer->TIMES(phythonLexer)
 *  - 
 void
      phythonLexer->DOT(phythonLexer)
 *  - 
 void
      phythonLexer->ASSIGN(phythonLexer)
 *  - 
 void
      phythonLexer->BLOCK(phythonLexer)
 *  - 
 void
      phythonLexer->DEF(phythonLexer)
 *  - 
 void
      phythonLexer->INT(phythonLexer)
 *  - 
 void
      phythonLexer->ID(phythonLexer)
 *  - 
 void
      phythonLexer->FLOAT(phythonLexer)
 *  - 
 void
      phythonLexer->COMMENT(phythonLexer)
 *  - 
 void
      phythonLexer->WS(phythonLexer)
 *  - 
 void
      phythonLexer->STRING(phythonLexer)
 *  - 
 void
      phythonLexer->EXPONENT(phythonLexer)
 *  - 
 void
      phythonLexer->HEX_DIGIT(phythonLexer)
 *  - 
 void
      phythonLexer->ESC_SEQ(phythonLexer)
 *  - 
 void
      phythonLexer->OCTAL_ESC(phythonLexer)
 *  - 
 void
      phythonLexer->UNICODE_ESC(phythonLexer)
 *  - 
 void
      phythonLexer->Tokens(phythonLexer)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_hythonLexer_H
#define _hythonLexer_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct hythonLexer_Ctx_struct hythonLexer, * phythonLexer;



#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif

/** Context tracking structure for 
hythonLexer

 */
struct hythonLexer_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_LEXER    pLexer;

     void
     (*mT__39)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mT__40)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mT__41)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mT__42)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mT__43)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mMOD)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mDIV)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mDO)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mDOWHILE)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mWHILE)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mFOR)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mPRINT)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mIF)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mELSE)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mOR)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mAND)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mGE)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mNE)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mLITTLE)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mLE)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mGT)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mEQ)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mPLUS)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mMINUS)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mTIMES)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mDOT)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mASSIGN)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mBLOCK)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mDEF)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mINT)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mID)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mFLOAT)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mCOMMENT)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mWS)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mSTRING)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mEXPONENT)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mHEX_DIGIT)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mESC_SEQ)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mOCTAL_ESC)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mUNICODE_ESC)	(struct hythonLexer_Ctx_struct * ctx);

     void
     (*mTokens)	(struct hythonLexer_Ctx_struct * ctx);
    const char * (*getGrammarFileName)();
    void            (*reset)  (struct hythonLexer_Ctx_struct * ctx);
    void	    (*free)   (struct hythonLexer_Ctx_struct * ctx);
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API phythonLexer hythonLexerNew         (
pANTLR3_INPUT_STREAM
 instream);
ANTLR3_API phythonLexer hythonLexerNewSSD      (
pANTLR3_INPUT_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
lexer
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define T__39      39
#define T__40      40
#define T__41      41
#define T__42      42
#define T__43      43
#define AND      4
#define ASSIGN      5
#define BLOCK      6
#define COMMENT      7
#define DEF      8
#define DIV      9
#define DO      10
#define DOT      11
#define DOWHILE      12
#define ELSE      13
#define EQ      14
#define ESC_SEQ      15
#define EXPONENT      16
#define FLOAT      17
#define FOR      18
#define GE      19
#define GT      20
#define HEX_DIGIT      21
#define ID      22
#define IF      23
#define INT      24
#define LE      25
#define LITTLE      26
#define MINUS      27
#define MOD      28
#define NE      29
#define OCTAL_ESC      30
#define OR      31
#define PLUS      32
#define PRINT      33
#define STRING      34
#define TIMES      35
#define UNICODE_ESC      36
#define WHILE      37
#define WS      38
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for hythonLexer
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
