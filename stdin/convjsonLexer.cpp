
#include "convjsonLexer"

#include <quex/code_base/analyzer/C-adaptions.h>
/* The file 'multi.i' contains implementations which are the same for all 
 * possibly generated analyzers. If QUEX_OPTION_MULTI is defined, it is
 * NOT supposed to be included here. If not--in which case we have a single
 * analzer--then it is included.                                             */
#include <quex/code_base/single.i>

QUEX_NAMESPACE_MAIN_OPEN
QUEX_NAME(Mode) QUEX_NAME(CONVERTER) = {
    /* id                */ QUEX_NAME(ModeID_CONVERTER),
    /* name              */ "CONVERTER",
#   if      defined(QUEX_OPTION_INDENTATION_TRIGGER) \
       && ! defined(QUEX_OPTION_INDENTATION_DEFAULT_HANDLER)
    /* on_indentation    */ QUEX_NAME(Mode_on_indentation_null_function),
#   endif
    /* on_entry          */ QUEX_NAME(Mode_on_entry_exit_null_function),
    /* on_exit           */ QUEX_NAME(Mode_on_entry_exit_null_function),
#   if      defined(QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK)
    /* has_base          */ QUEX_NAME(CONVERTER_has_base),
    /* has_entry_from    */ QUEX_NAME(CONVERTER_has_entry_from),
    /* has_exit_to       */ QUEX_NAME(CONVERTER_has_exit_to),
#   endif
    /* analyzer_function */ QUEX_NAME(CONVERTER_analyzer_function)
};

QUEX_NAME(Mode)* (QUEX_NAME(mode_db)[__QUEX_SETTING_MAX_MODE_CLASS_N]) = {
    &QUEX_NAME(CONVERTER)
};
#define self        (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
#define LexemeNull  (&QUEX_LEXEME_NULL)
#define RETURN      return

void
QUEX_NAME(CONVERTER_on_entry)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* FromMode) {
    (void)me;
    (void)FromMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(CONVERTER).has_entry_from(FromMode);
#   endif

}

void
QUEX_NAME(CONVERTER_on_exit)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* ToMode)  {
    (void)me;
    (void)ToMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(CONVERTER).has_exit_to(ToMode);
#   endif

}

#if defined(QUEX_OPTION_INDENTATION_TRIGGER) 
void
QUEX_NAME(CONVERTER_on_indentation)(QUEX_TYPE_ANALYZER*    me, 
                                        QUEX_TYPE_INDENTATION  Indentation, 
                                        QUEX_TYPE_LEXATOM*   Begin) {
    (void)me;
    (void)Indentation;
    (void)Begin;
    return;
}
#endif

#ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
bool
QUEX_NAME(CONVERTER_has_base)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return false;
}
bool
QUEX_NAME(CONVERTER_has_entry_from)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
switch( Mode->id ) {

    case QUEX_NAME(ModeID_CONVERTER): {

    return true;
    }

    default: {

    return true;
    }

    }

}
bool
QUEX_NAME(CONVERTER_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
switch( Mode->id ) {

    case QUEX_NAME(ModeID_CONVERTER): {

    return true;
    }

    default: {

    return true;
    }

    }

}
#endif    
#undef self
#undef LexemeNull
#undef RETURN
QUEX_NAMESPACE_MAIN_CLOSE

/* #include "convjsonLexer"*/
QUEX_NAMESPACE_MAIN_OPEN
#ifdef      QUEX_FUNCTION_COUNT_ARBITRARY
#   undef   QUEX_FUNCTION_COUNT_ARBITRARY
#endif
#ifdef      QUEX_OPTION_COUNTER
#    define QUEX_FUNCTION_COUNT_ARBITRARY(ME, BEGIN, END) \
            do {                              \
                QUEX_NAME(CONVERTER_counter)((ME), (BEGIN), (END));     \
                __quex_debug_counter();       \
            } while(0)
#else
#    define QUEX_FUNCTION_COUNT_ARBITRARY(ME, BEGIN, END) /* empty */
#endif
#ifdef QUEX_OPTION_COUNTER
static void
QUEX_NAME(CONVERTER_counter)(QUEX_TYPE_ANALYZER* me, QUEX_TYPE_LEXATOM* LexemeBegin, QUEX_TYPE_LEXATOM* LexemeEnd)
{
#   define self (*me)
/*  'QUEX_GOTO_STATE' requires 'QUEX_LABEL_STATE_ROUTER' */
#   define QUEX_LABEL_STATE_ROUTER _20
    QUEX_TYPE_LEXATOM              input                          = (QUEX_TYPE_LEXATOM)(0x00);
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
#   ifdef QUEX_OPTION_COUNTER_COLUMN
    QUEX_TYPE_LEXATOM*             count_reference_p              = (QUEX_TYPE_LEXATOM*)0x0;
#   endif /* QUEX_OPTION_COUNTER_COLUMN */
    (void)me;
    __QUEX_IF_COUNT_SHIFT_VALUES();
    /* Allow LexemeBegin == LexemeEnd (e.g. END_OF_STREAM)
     * => Caller does not need to check
     * BUT, if so quit immediately after 'shift values'.
     */
    __quex_assert(LexemeBegin <= LexemeEnd);
    if( LexemeBegin == LexemeEnd ) {
        return;
    }
    me->buffer._read_p = LexemeBegin;

    /* (297476 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_14:
    __quex_debug("Init State\n");
    __quex_debug_state(297476);
if( input < 0xA ) {
if     ( input < 0x0 )  goto _5;
else if( input < 0x9 )  goto _4;
else                    goto _3;
} else {
if     ( input == 0xA )      goto _2;
else if( input < 0x110000 )  goto _4;
else                         goto _5;
}


    __quex_assert_no_passage();
_9:
    /* (297476 from 297480)  */
    goto _14;


    __quex_assert_no_passage();
_8:
    /* (DROP_OUT from 297479)  */
    goto _13;
_15:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_6:
    /* (DROP_OUT from 297477)  */
    goto _11;


    __quex_assert_no_passage();
_7:
    /* (DROP_OUT from 297478)  */
    goto _12;


    __quex_assert_no_passage();
_5:
    /* (DROP_OUT from 297476)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _16;
    goto _15;


    __quex_assert_no_passage();
_2:
    /* (297477 from 297476)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297477);
goto _6;


    __quex_assert_no_passage();
_3:
    /* (297478 from 297476)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297478);
goto _7;


    __quex_assert_no_passage();
_4:
    /* (297479 from 297476)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297479);
goto _8;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_10:
    __quex_debug("* TERMINAL <LOOP EXIT>\n");
    --(me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _0;

_11:
    __quex_debug("* TERMINAL <LOOP 1776>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_12:
    __quex_debug("* TERMINAL <LOOP 1777>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_13:
    __quex_debug("* TERMINAL <LOOP 1778>\n");
if( me->buffer._read_p != LexemeEnd ) goto _9;

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _0;

if(0) {
    /* Avoid unreferenced labels. */
    goto _10;
    goto _11;
    goto _12;
    goto _13;
}
_21: /* TERMINAL: BAD_LEXATOM */
;
_16: /* TERMINAL: FAILURE     */
goto _0;
_0:
/* Assert: lexeme in codec's character boundaries. */

     __quex_assert(me->buffer._read_p == LexemeEnd);
    return;
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
_20:
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */

#undef self


#undef QUEX_LABEL_STATE_ROUTER

#    if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
     goto _20; /* in QUEX_GOTO_STATE       */
     goto _21; /* to BAD_LEXATOM           */
#    endif
    /* Avoid compiler warning: 'Unused labels' */

    goto _16;
    (void)target_state_index;
    (void)target_state_else_index;
}
#endif /* QUEX_OPTION_COUNTER */

#include <quex/code_base/buffer/Buffer>
#include <quex/code_base/token/TokenQueue>

#ifdef    CONTINUE
#   undef CONTINUE
#endif
#define   CONTINUE do { goto _118; } while(0)

#ifdef    RETURN
#   undef RETURN
#endif
#define   RETURN   do { goto _117; } while(0)

__QUEX_TYPE_ANALYZER_RETURN_VALUE  
QUEX_NAME(CONVERTER_analyzer_function)(QUEX_TYPE_ANALYZER* me) 
{
    /* NOTE: Different modes correspond to different analyzer functions. The 
     *       analyzer functions are all located inside the main class as static
     *       functions. That means, they are something like 'globals'. They 
     *       receive a pointer to the lexical analyzer, since static members do
     *       not have access to the 'this' pointer.                          */
#   ifdef     self
#       undef self
#   endif
#   define self (*((QUEX_TYPE_ANALYZER*)me))
/*  'QUEX_GOTO_STATE' requires 'QUEX_LABEL_STATE_ROUTER' */
#   define QUEX_LABEL_STATE_ROUTER _121
#   define CONVERTER    (QUEX_NAME(CONVERTER))

    /* Lexeme setup: 
     *
     * There is a temporary zero stored at the end of each lexeme, if the action 
     * references to the 'Lexeme'. 'LexemeNull' provides a reference to an empty
     * zero terminated string.                                                    */
#if defined(QUEX_OPTION_ASSERTS)
#   define Lexeme       QUEX_NAME(access_Lexeme)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeBegin  QUEX_NAME(access_LexemeBegin)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeL      QUEX_NAME(access_LexemeL)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeEnd    QUEX_NAME(access_LexemeEnd)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#else
#   define Lexeme       (me->buffer._lexeme_start_p)
#   define LexemeBegin  Lexeme
#   define LexemeL      ((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p))
#   define LexemeEnd    me->buffer._read_p
#endif

#define LexemeNull      (&QUEX_LEXEME_NULL)
    E_LoadResult                   load_result                    = E_LoadResult_VOID;
    QUEX_TYPE_LEXATOM**            position                       = 0x0;
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
    const size_t                   PositionRegisterN              = (size_t)0;
    QUEX_TYPE_LEXATOM              input                          = (QUEX_TYPE_LEXATOM)(0x00);
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;

    /* Post context positions do not have to be reset or initialized. If a state
     * is reached which is associated with 'end of post context' it is clear what
     * post context is meant. This results from the ways the state machine is 
     * constructed. Post context position's live cycle:
     *
     * (1)   unitialized (don't care)
     * (1.b) on buffer reload it may, or may not be adapted (don't care)
     * (2)   when a post context begin state is passed, then it is **SET** (now: take care)
     * (2.b) on buffer reload it **is adapted**.
     * (3)   when a terminal state of the post context is reached (which can only be reached
     *       for that particular post context), then the post context position is used
     *       to reset the input position.                                              */
#   if defined(QUEX_OPTION_ASSERTS)
    me->DEBUG_analyzer_function_at_entry = me->current_analyzer_function;
#   endif
_120:
    me->buffer._lexeme_start_p = me->buffer._read_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);
_27:
    /* (297453 from BEFORE_ENTRY) (297453 from RELOAD_FORWARD)  */

    input = *(me->buffer._read_p);


    __quex_debug("Init State\n");
    __quex_debug_state(297453);
if( input < 0x27C0 ) {
if( input < 0x1E00 ) {
if( input < 0x85 ) {
switch( input ) {
case 0x0: goto _71;
case 0x9: goto _35;
case 0xA: case 0xB: case 0xC: case 0xD: goto _28;
case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: 
case 0x28: case 0x29: case 0x2A: case 0x2B: case 0x2C: case 0x2D: case 0x2E: case 0x2F: 
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: case 0x3A: case 0x3B: case 0x3C: case 0x3D: case 0x3E: case 0x3F: 
case 0x40: case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: case 0x5B: case 0x5C: case 0x5D: case 0x5E: case 0x5F: 
case 0x60: case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: case 0x7B: case 0x7C: case 0x7D: case 0x7E: goto _35;
default: goto _49;
}
} else {
if( input < 0xAE ) {
if     ( input == 0x85 )  goto _28;
else if( input < 0xA0 )   goto _49;
else if( input < 0xAD )   goto _35;
else                      goto _49;
} else {
if     ( input < 0x250 )   goto _35;
else if( input < 0x2B0 )   goto _49;
else if( input < 0x530 )   goto _35;
else if( input < 0x1D00 )  goto _49;
else                       goto _35;
}
}
} else {
if( input < 0x2066 ) {
if( input < 0x2028 ) {
if     ( input < 0x1F00 )  goto _49;
else if( input < 0x200B )  goto _35;
else if( input < 0x2010 )  goto _49;
else                       goto _35;
} else {
if     ( input < 0x202A )  goto _28;
else if( input < 0x202F )  goto _49;
else if( input < 0x2060 )  goto _35;
else if( input < 0x2065 )  goto _49;
else                       goto _35;
}
} else {
if( input < 0x2150 ) {
if     ( input < 0x20A0 )  goto _49;
else if( input < 0x20D0 )  goto _35;
else if( input < 0x2100 )  goto _49;
else                       goto _35;
} else {
if     ( input < 0x2190 )  goto _49;
else if( input < 0x2400 )  goto _35;
else if( input < 0x25A0 )  goto _49;
else if( input < 0x2700 )  goto _35;
else                       goto _49;
}
}
}
} else {
if( input < 0x10190 ) {
if( input < 0xA720 ) {
if( input < 0x2C60 ) {
if     ( input < 0x2800 )  goto _35;
else if( input < 0x2900 )  goto _49;
else if( input < 0x2C00 )  goto _35;
else                       goto _49;
} else {
if     ( input < 0x2C80 )  goto _35;
else if( input < 0x2E00 )  goto _49;
else if( input < 0x2E80 )  goto _35;
else                       goto _49;
}
} else {
if( input < 0xFFF0 ) {
if     ( input < 0xA800 )  goto _35;
else if( input < 0xFB00 )  goto _49;
else if( input < 0xFB50 )  goto _35;
else                       goto _49;
} else {
if     ( input < 0xFFF9 )   goto _35;
else if( input < 0xFFFC )   goto _49;
else if( input < 0x10000 )  goto _35;
else if( input < 0x10140 )  goto _49;
else                        goto _35;
}
}
} else {
if( input < 0x1F032 ) {
if( input < 0x1D200 ) {
if     ( input < 0x1D100 )  goto _49;
else if( input < 0x1D173 )  goto _35;
else if( input < 0x1D17B )  goto _49;
else                        goto _35;
} else {
if( input < 0x1D800 ) {
if( input < 0x1D400 )  goto _49;
else                   goto _35;
} else {
if     ( input < 0x1F030 )   goto _49;
else if( input == 0x1F030 )  goto _31;
else                         goto _29;
}
}
} else {
if( input < 0x1F036 ) {
switch( input ) {
case 0x1F032: goto _34;
case 0x1F034: goto _30;
case 0x1F035: goto _36;
default: goto _32;
}
} else {
if( input < 0x1F038 ) {
if( input == 0x1F037 )  goto _37;
else                    goto _33;
} else {
if     ( input < 0x1F600 )  goto _49;
else if( input < 0x1F916 )  goto _35;
else                        goto _49;
}
}
}
}
}


    __quex_assert_no_passage();
_58:
    /* (DROP_OUT from 297462)  */
    goto _19;
_86:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_50:
    /* (DROP_OUT from 297454)  */
    goto _1;


    __quex_assert_no_passage();
_51:
    /* (DROP_OUT from 297455)  */
    goto _17;


    __quex_assert_no_passage();
_52:
    /* (DROP_OUT from 297456)  */
    goto _15;


    __quex_assert_no_passage();
_53:
    /* (DROP_OUT from 297457)  */
    goto _13;


    __quex_assert_no_passage();
_54:
    /* (DROP_OUT from 297458)  */
    goto _18;


    __quex_assert_no_passage();
_55:
    /* (DROP_OUT from 297459)  */
    goto _16;


    __quex_assert_no_passage();
_56:
    /* (DROP_OUT from 297460)  */
    goto _14;


    __quex_assert_no_passage();
_57:
    /* (DROP_OUT from 297461)  */
    goto _0;


    __quex_assert_no_passage();
_59:
    /* (DROP_OUT from 297463)  */
    goto _20;


    __quex_assert_no_passage();
_60:
    /* (DROP_OUT from 297464)  */
    goto _10;


    __quex_assert_no_passage();
_61:
    /* (DROP_OUT from 297465)  */
    goto _11;


    __quex_assert_no_passage();
_62:
    /* (DROP_OUT from 297466)  */
    goto _12;


    __quex_assert_no_passage();
_63:
    /* (DROP_OUT from 297467)  */
    goto _8;


    __quex_assert_no_passage();
_64:
    /* (DROP_OUT from 297468)  */
    goto _9;


    __quex_assert_no_passage();
_65:
    /* (DROP_OUT from 297469)  */
    goto _7;


    __quex_assert_no_passage();
_66:
    /* (DROP_OUT from 297470)  */
    goto _4;


    __quex_assert_no_passage();
_67:
    /* (DROP_OUT from 297471)  */
    goto _5;


    __quex_assert_no_passage();
_68:
    /* (DROP_OUT from 297472)  */
    goto _6;


    __quex_assert_no_passage();
_69:
    /* (DROP_OUT from 297473)  */
    goto _2;


    __quex_assert_no_passage();
_70:
    /* (DROP_OUT from 297474)  */
    goto _3;


    __quex_assert_no_passage();
_49:
    /* (DROP_OUT from 297453)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _25;
    goto _86;


    __quex_assert_no_passage();
_46:
    /* (297472 from 297458)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297472);
goto _68;


    __quex_assert_no_passage();
_47:
    /* (297473 from 297455)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297473);
goto _69;


    __quex_assert_no_passage();
_48:
    /* (297474 from 297455)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297474);
goto _70;


    __quex_assert_no_passage();
_28:
    /* (297454 from 297453) (297454 from 297454)  */

    ++(me->buffer._read_p);

_92:
    input = *(me->buffer._read_p);


    __quex_debug_state(297454);
switch( input ) {
case 0x0: goto _73;
case 0xA: case 0xB: case 0xC: case 0xD: 
case 0x85: 
case 0x2028: case 0x2029: goto _28;
default: goto _50;
}


    __quex_assert_no_passage();
_72:
    /* (297454 from RELOAD_FORWARD)  */
    goto _92;


    __quex_assert_no_passage();
_29:
    /* (297455 from 297453)  */
    ++(me->buffer._read_p);

_94:
    input = *(me->buffer._read_p);


    __quex_debug_state(297455);
switch( input ) {
case 0x0: goto _75;
case 0x1F030: goto _48;
case 0x1F032: goto _47;
default: goto _51;
}


    __quex_assert_no_passage();
_74:
    /* (297455 from RELOAD_FORWARD)  */
    goto _94;


    __quex_assert_no_passage();
_30:
    /* (297456 from 297453)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297456);
goto _52;


    __quex_assert_no_passage();
_31:
    /* (297457 from 297453)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297457);
goto _53;


    __quex_assert_no_passage();
_76:
    /* (297458 from RELOAD_FORWARD)  */
_98:
    input = *(me->buffer._read_p);


    __quex_debug_state(297458);
switch( input ) {
case 0x0: goto _77;
case 0x1F030: goto _44;
case 0x1F034: goto _45;
case 0x1F036: goto _46;
default: goto _54;
}


    __quex_assert_no_passage();
_32:
    /* (297458 from 297453)  */
    ++(me->buffer._read_p);

    goto _98;


    __quex_assert_no_passage();
_33:
    /* (297459 from 297453)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297459);
goto _55;


    __quex_assert_no_passage();
_34:
    /* (297460 from 297453)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297460);
goto _56;


    __quex_assert_no_passage();
_35:
    /* (297461 from 297453) (297461 from 297461)  */

    ++(me->buffer._read_p);

_103:
    input = *(me->buffer._read_p);


    __quex_debug_state(297461);
if( input < 0x2400 ) {
if( input < 0x1E00 ) {
if( input < 0xA0 ) {
switch( input ) {
case 0x0: goto _79;
case 0x9: 
case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: 
case 0x28: case 0x29: case 0x2A: case 0x2B: case 0x2C: case 0x2D: case 0x2E: case 0x2F: 
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: case 0x3A: case 0x3B: case 0x3C: case 0x3D: case 0x3E: case 0x3F: 
case 0x40: case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: case 0x5B: case 0x5C: case 0x5D: case 0x5E: case 0x5F: 
case 0x60: case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: case 0x7B: case 0x7C: case 0x7D: case 0x7E: goto _35;
default: goto _57;
}
} else {
if( input < 0x250 ) {
if( input == 0xAD )  goto _57;
else                 goto _35;
} else {
if     ( input < 0x2B0 )   goto _57;
else if( input < 0x530 )   goto _35;
else if( input < 0x1D00 )  goto _57;
else                       goto _35;
}
}
} else {
if( input < 0x2065 ) {
if( input < 0x2010 ) {
if     ( input < 0x1F00 )  goto _57;
else if( input < 0x200B )  goto _35;
else                       goto _57;
} else {
if     ( input < 0x2028 )  goto _35;
else if( input < 0x202F )  goto _57;
else if( input < 0x2060 )  goto _35;
else                       goto _57;
}
} else {
switch( input ) {
case 0x2066: case 0x2067: 
case 0x2068: case 0x2069: case 0x206A: case 0x206B: case 0x206C: case 0x206D: case 0x206E: case 0x206F: 
case 0x2070: case 0x2071: case 0x2072: case 0x2073: case 0x2074: case 0x2075: case 0x2076: case 0x2077: 
case 0x2078: case 0x2079: case 0x207A: case 0x207B: case 0x207C: case 0x207D: case 0x207E: case 0x207F: 
case 0x2080: case 0x2081: case 0x2082: case 0x2083: case 0x2084: case 0x2085: case 0x2086: case 0x2087: 
case 0x2088: case 0x2089: case 0x208A: case 0x208B: case 0x208C: case 0x208D: case 0x208E: case 0x208F: 
case 0x2090: case 0x2091: case 0x2092: case 0x2093: case 0x2094: case 0x2095: case 0x2096: case 0x2097: 
case 0x2098: case 0x2099: case 0x209A: case 0x209B: case 0x209C: case 0x209D: case 0x209E: case 0x209F: 
case 0x20D0: case 0x20D1: case 0x20D2: case 0x20D3: case 0x20D4: case 0x20D5: case 0x20D6: case 0x20D7: 
case 0x20D8: case 0x20D9: case 0x20DA: case 0x20DB: case 0x20DC: case 0x20DD: case 0x20DE: case 0x20DF: 
case 0x20E0: case 0x20E1: case 0x20E2: case 0x20E3: case 0x20E4: case 0x20E5: case 0x20E6: case 0x20E7: 
case 0x20E8: case 0x20E9: case 0x20EA: case 0x20EB: case 0x20EC: case 0x20ED: case 0x20EE: case 0x20EF: 
case 0x20F0: case 0x20F1: case 0x20F2: case 0x20F3: case 0x20F4: case 0x20F5: case 0x20F6: case 0x20F7: 
case 0x20F8: case 0x20F9: case 0x20FA: case 0x20FB: case 0x20FC: case 0x20FD: case 0x20FE: case 0x20FF: 
case 0x2150: case 0x2151: case 0x2152: case 0x2153: case 0x2154: case 0x2155: case 0x2156: case 0x2157: 
case 0x2158: case 0x2159: case 0x215A: case 0x215B: case 0x215C: case 0x215D: case 0x215E: case 0x215F: 
case 0x2160: case 0x2161: case 0x2162: case 0x2163: case 0x2164: case 0x2165: case 0x2166: case 0x2167: 
case 0x2168: case 0x2169: case 0x216A: case 0x216B: case 0x216C: case 0x216D: case 0x216E: case 0x216F: 
case 0x2170: case 0x2171: case 0x2172: case 0x2173: case 0x2174: case 0x2175: case 0x2176: case 0x2177: 
case 0x2178: case 0x2179: case 0x217A: case 0x217B: case 0x217C: case 0x217D: case 0x217E: case 0x217F: 
case 0x2180: case 0x2181: case 0x2182: case 0x2183: case 0x2184: case 0x2185: case 0x2186: case 0x2187: 
case 0x2188: case 0x2189: case 0x218A: case 0x218B: case 0x218C: case 0x218D: case 0x218E: case 0x218F: goto _57;
default: goto _35;
}
}
}
} else {
if( input < 0xFB50 ) {
if( input < 0x2C60 ) {
if( input < 0x27C0 ) {
if     ( input < 0x25A0 )  goto _57;
else if( input < 0x2700 )  goto _35;
else                       goto _57;
} else {
if     ( input < 0x2800 )  goto _35;
else if( input < 0x2900 )  goto _57;
else if( input < 0x2C00 )  goto _35;
else                       goto _57;
}
} else {
if( input < 0x2E80 ) {
if     ( input < 0x2C80 )  goto _35;
else if( input < 0x2E00 )  goto _57;
else                       goto _35;
} else {
if     ( input < 0xA720 )  goto _57;
else if( input < 0xA800 )  goto _35;
else if( input < 0xFB00 )  goto _57;
else                       goto _35;
}
}
} else {
if( input < 0x1D100 ) {
switch( input ) {
case 0xFFF0: case 0xFFF1: case 0xFFF2: case 0xFFF3: case 0xFFF4: case 0xFFF5: case 0xFFF6: case 0xFFF7: 
case 0xFFF8: 
case 0xFFFC: case 0xFFFD: case 0xFFFE: case 0xFFFF: 
case 0x10140: case 0x10141: case 0x10142: case 0x10143: case 0x10144: case 0x10145: case 0x10146: case 0x10147: 
case 0x10148: case 0x10149: case 0x1014A: case 0x1014B: case 0x1014C: case 0x1014D: case 0x1014E: case 0x1014F: 
case 0x10150: case 0x10151: case 0x10152: case 0x10153: case 0x10154: case 0x10155: case 0x10156: case 0x10157: 
case 0x10158: case 0x10159: case 0x1015A: case 0x1015B: case 0x1015C: case 0x1015D: case 0x1015E: case 0x1015F: 
case 0x10160: case 0x10161: case 0x10162: case 0x10163: case 0x10164: case 0x10165: case 0x10166: case 0x10167: 
case 0x10168: case 0x10169: case 0x1016A: case 0x1016B: case 0x1016C: case 0x1016D: case 0x1016E: case 0x1016F: 
case 0x10170: case 0x10171: case 0x10172: case 0x10173: case 0x10174: case 0x10175: case 0x10176: case 0x10177: 
case 0x10178: case 0x10179: case 0x1017A: case 0x1017B: case 0x1017C: case 0x1017D: case 0x1017E: case 0x1017F: 
case 0x10180: case 0x10181: case 0x10182: case 0x10183: case 0x10184: case 0x10185: case 0x10186: case 0x10187: 
case 0x10188: case 0x10189: case 0x1018A: case 0x1018B: case 0x1018C: case 0x1018D: case 0x1018E: case 0x1018F: goto _35;
default: goto _57;
}
} else {
if( input < 0x1D400 ) {
if     ( input < 0x1D173 )  goto _35;
else if( input < 0x1D17B )  goto _57;
else if( input < 0x1D200 )  goto _35;
else                        goto _57;
} else {
if     ( input < 0x1D800 )  goto _35;
else if( input < 0x1F600 )  goto _57;
else if( input < 0x1F916 )  goto _35;
else                        goto _57;
}
}
}
}


    __quex_assert_no_passage();
_78:
    /* (297461 from RELOAD_FORWARD)  */
    goto _103;


    __quex_assert_no_passage();
_80:
    /* (297462 from RELOAD_FORWARD)  */
_105:
    input = *(me->buffer._read_p);


    __quex_debug_state(297462);
switch( input ) {
case 0x0: goto _81;
case 0x1F032: goto _43;
case 0x1F034: goto _41;
case 0x1F036: goto _42;
default: goto _58;
}


    __quex_assert_no_passage();
_36:
    /* (297462 from 297453)  */
    ++(me->buffer._read_p);

    goto _105;


    __quex_assert_no_passage();
_37:
    /* (297463 from 297453)  */
    ++(me->buffer._read_p);

_107:
    input = *(me->buffer._read_p);


    __quex_debug_state(297463);
switch( input ) {
case 0x0: goto _83;
case 0x1F032: goto _38;
case 0x1F034: goto _39;
case 0x1F036: goto _40;
default: goto _59;
}


    __quex_assert_no_passage();
_82:
    /* (297463 from RELOAD_FORWARD)  */
    goto _107;


    __quex_assert_no_passage();
_38:
    /* (297464 from 297463)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297464);
goto _60;


    __quex_assert_no_passage();
_39:
    /* (297465 from 297463)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297465);
goto _61;


    __quex_assert_no_passage();
_40:
    /* (297466 from 297463)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297466);
goto _62;


    __quex_assert_no_passage();
_41:
    /* (297467 from 297462)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297467);
goto _63;


    __quex_assert_no_passage();
_42:
    /* (297468 from 297462)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297468);
goto _64;


    __quex_assert_no_passage();
_43:
    /* (297469 from 297462)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297469);
goto _65;


    __quex_assert_no_passage();
_44:
    /* (297470 from 297458)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297470);
goto _66;


    __quex_assert_no_passage();
_45:
    /* (297471 from 297458)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297471);
goto _67;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_21:
    __quex_debug("* TERMINAL BAD_LEXATOM\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{
self.error_code = E_Error_NoHandler_OnBadLexatom;
self_send(QUEX_TOKEN_ID(TERMINATION));
__QUEX_PURE_RETURN;;

}
    /* Bad lexatom detection FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
__QUEX_PURE_RETURN;
_22:
    __quex_debug("* TERMINAL LOAD_FAILURE\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{
self.error_code = E_Error_NoHandler_OnLoadFailure;
self_send(QUEX_TOKEN_ID(TERMINATION));
__QUEX_PURE_RETURN;;

}
    /* Load failure FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
__QUEX_PURE_RETURN;
_23:
    __quex_debug("* TERMINAL OVERFLOW\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{
self.error_code = E_Error_NoHandler_OnOverflow;
self_send(QUEX_TOKEN_ID(TERMINATION));
__QUEX_PURE_RETURN;;

}
    /* Lexeme size exceeds buffer size. No further buffer load possible.
     */
__QUEX_PURE_RETURN;
_24:
    __quex_debug("* TERMINAL END_OF_STREAM\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 41 "convjson.qx"
self_send(convjson_TERMINATION);

__QUEX_PURE_RETURN;


#   line 1181 "convjsonLexer.cpp"

}
    /* End of Stream FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
__QUEX_PURE_RETURN;
_25:
    __quex_debug("* TERMINAL FAILURE\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 39 "convjson.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(convjson_FAILURE);

__QUEX_PURE_RETURN;


#   line 1200 "convjsonLexer.cpp"

}
RETURN;
_26:
    __quex_debug("* TERMINAL SKIP_RANGE_OPEN\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{
#define Counter counter
self.error_code = E_Error_NoHandler_OnSkipRangeOpen;
self_send(QUEX_TOKEN_ID(TERMINATION));
__QUEX_PURE_RETURN;;

}
    /* End of Stream appeared, while scanning for end of skip-range.
     */
__QUEX_PURE_RETURN;
_0:
    __quex_debug("* TERMINAL [: difference({BASE_CLASS}, {NEWLINECHAR}) :]+\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 12 "convjson.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(convjson_ANYCHAR);

__QUEX_PURE_RETURN;


#   line 1229 "convjsonLexer.cpp"

}
RETURN;
_1:
    __quex_debug("* TERMINAL {NEWLINECHAR}+\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 13 "convjson.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(convjson_ANYCHAR);

__QUEX_PURE_RETURN;


#   line 1245 "convjsonLexer.cpp"

}
RETURN;
_2:
    __quex_debug("* TERMINAL {SNT_CLOSE_QX}{WS_OPEN_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 16 "convjson.qx"
self_write_token_p()->text = L"],\n\"ws\": \"";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1262 "convjsonLexer.cpp"

}
RETURN;
_3:
    __quex_debug("* TERMINAL {SNT_CLOSE_QX}{SNT_OPEN_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 17 "convjson.qx"
self_write_token_p()->text = L"],\n\"s\": [\n";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1279 "convjsonLexer.cpp"

}
RETURN;
_4:
    __quex_debug("* TERMINAL {WS_CLOSE_QX}{SNT_OPEN_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 18 "convjson.qx"
self_write_token_p()->text = L"\",\n\"s\": [\n";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1296 "convjsonLexer.cpp"

}
RETURN;
_5:
    __quex_debug("* TERMINAL {WS_CLOSE_QX}{WORD_OPEN_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 19 "convjson.qx"
self_write_token_p()->text = L"\",\n\"w\": \"";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1313 "convjsonLexer.cpp"

}
RETURN;
_6:
    __quex_debug("* TERMINAL {WS_CLOSE_QX}{PUNCT_OPEN_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 20 "convjson.qx"
self_write_token_p()->text = L"\",\n\"c\": \"";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1330 "convjsonLexer.cpp"

}
RETURN;
_7:
    __quex_debug("* TERMINAL {WORD_CLOSE_QX}{WS_OPEN_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 21 "convjson.qx"
self_write_token_p()->text = L"\",\n\"ws\": \"";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1347 "convjsonLexer.cpp"

}
RETURN;
_8:
    __quex_debug("* TERMINAL {WORD_CLOSE_QX}{WORD_OPEN_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 22 "convjson.qx"
self_write_token_p()->text = L"\",\n\"w\": \"";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1364 "convjsonLexer.cpp"

}
RETURN;
_9:
    __quex_debug("* TERMINAL {WORD_CLOSE_QX}{PUNCT_OPEN_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 23 "convjson.qx"
self_write_token_p()->text = L"\",\n\"c\": \"";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1381 "convjsonLexer.cpp"

}
RETURN;
_10:
    __quex_debug("* TERMINAL {PUNCT_CLOSE_QX}{WS_OPEN_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 24 "convjson.qx"
self_write_token_p()->text = L"\",\n\"ws\": \"";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1398 "convjsonLexer.cpp"

}
RETURN;
_11:
    __quex_debug("* TERMINAL {PUNCT_CLOSE_QX}{WORD_OPEN_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 25 "convjson.qx"
self_write_token_p()->text = L"\",\n\"w\": \"";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1415 "convjsonLexer.cpp"

}
RETURN;
_12:
    __quex_debug("* TERMINAL {PUNCT_CLOSE_QX}{PUNCT_OPEN_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 26 "convjson.qx"
self_write_token_p()->text = L"\",\n\"c\": \"";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1432 "convjsonLexer.cpp"

}
RETURN;
_13:
    __quex_debug("* TERMINAL {SNT_OPEN_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 28 "convjson.qx"
self_write_token_p()->text = L"\"s\": [\n";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1449 "convjsonLexer.cpp"

}
RETURN;
_14:
    __quex_debug("* TERMINAL {WS_OPEN_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 29 "convjson.qx"
self_write_token_p()->text = L"\"ws\": \"";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1466 "convjsonLexer.cpp"

}
RETURN;
_15:
    __quex_debug("* TERMINAL {WORD_OPEN_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 30 "convjson.qx"
self_write_token_p()->text = L"\"w\": \"";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1483 "convjsonLexer.cpp"

}
RETURN;
_16:
    __quex_debug("* TERMINAL {PUNCT_OPEN_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 31 "convjson.qx"
self_write_token_p()->text = L"\"c\": \"";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1500 "convjsonLexer.cpp"

}
RETURN;
_17:
    __quex_debug("* TERMINAL {SNT_CLOSE_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 33 "convjson.qx"
self_write_token_p()->text = L"]\n";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1517 "convjsonLexer.cpp"

}
RETURN;
_18:
    __quex_debug("* TERMINAL {WS_CLOSE_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 34 "convjson.qx"
self_write_token_p()->text = L"\"\n";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1534 "convjsonLexer.cpp"

}
RETURN;
_19:
    __quex_debug("* TERMINAL {WORD_CLOSE_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 35 "convjson.qx"
self_write_token_p()->text = L"\"\n";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1551 "convjsonLexer.cpp"

}
RETURN;
_20:
    __quex_debug("* TERMINAL {PUNCT_CLOSE_QX}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 36 "convjson.qx"
self_write_token_p()->text = L"\"\n";
self_send(convjson_TAG);

__QUEX_PURE_RETURN;


#   line 1568 "convjsonLexer.cpp"

}
RETURN;
if(0) {
    /* Avoid unreferenced labels. */
    goto _21;
    goto _22;
    goto _23;
    goto _24;
    goto _25;
    goto _26;
    goto _0;
    goto _1;
    goto _2;
    goto _3;
    goto _4;
    goto _5;
    goto _6;
    goto _7;
    goto _8;
    goto _9;
    goto _10;
    goto _11;
    goto _12;
    goto _13;
    goto _14;
    goto _15;
    goto _16;
    goto _17;
    goto _18;
    goto _19;
    goto _20;
}
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
_121:
switch( target_state_index ) {
case 24: {
goto _24;}
case 27: {
goto _27;}
case 50: {
goto _50;}
case 51: {
goto _51;}
case 54: {
goto _54;}
case 57: {
goto _57;}
case 58: {
goto _58;}
case 59: {
goto _59;}
case 72: {
goto _72;}
case 74: {
goto _74;}
case 76: {
goto _76;}
case 78: {
goto _78;}
case 80: {
goto _80;}
case 82: {
goto _82;}
default: {
goto _82;}
}
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */


    __quex_assert_no_passage();
_73:
    /* (RELOAD_FORWARD from 297454)  */
    target_state_index = QUEX_LABEL(72); target_state_else_index = QUEX_LABEL(50);

_116:

    __quex_debug3("RELOAD_FORWARD: success->%i; failure->%i", 
                  (int)target_state_index, (int)target_state_else_index);
    __quex_assert(*(me->buffer._read_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    
    __quex_debug_reload_before();                 
    load_result = QUEX_NAME(Buffer_load_forward)(&me->buffer, (QUEX_TYPE_LEXATOM**)position, PositionRegisterN);
    __quex_debug_reload_after(load_result);

    switch( load_result ) {
    case E_LoadResult_DONE:              QUEX_GOTO_STATE(target_state_index);      
    case E_LoadResult_BAD_LEXATOM:       goto _21;
    case E_LoadResult_FAILURE:           goto _22;
    case E_LoadResult_NO_SPACE_FOR_LOAD: goto _23;
    case E_LoadResult_NO_MORE_DATA:      QUEX_GOTO_STATE(target_state_else_index); 
    default:                             __quex_assert(false);
    }


    __quex_assert_no_passage();
_71:
    /* (RELOAD_FORWARD from 297453)  */
    target_state_index = QUEX_LABEL(27); target_state_else_index = QUEX_LABEL(24);

    goto _116;


    __quex_assert_no_passage();
_75:
    /* (RELOAD_FORWARD from 297455)  */
    target_state_index = QUEX_LABEL(74); target_state_else_index = QUEX_LABEL(51);

    goto _116;


    __quex_assert_no_passage();
_77:
    /* (RELOAD_FORWARD from 297458)  */
    target_state_index = QUEX_LABEL(76); target_state_else_index = QUEX_LABEL(54);

    goto _116;


    __quex_assert_no_passage();
_79:
    /* (RELOAD_FORWARD from 297461)  */
    target_state_index = QUEX_LABEL(78); target_state_else_index = QUEX_LABEL(57);

    goto _116;


    __quex_assert_no_passage();
_81:
    /* (RELOAD_FORWARD from 297462)  */
    target_state_index = QUEX_LABEL(80); target_state_else_index = QUEX_LABEL(58);

    goto _116;


    __quex_assert_no_passage();
_83:
    /* (RELOAD_FORWARD from 297463)  */
    target_state_index = QUEX_LABEL(82); target_state_else_index = QUEX_LABEL(59);

    goto _116;

_117:
/* RETURN -- after executing 'on_after_match' code. */
    __QUEX_PURE_RETURN;


_118:
/* CONTINUE -- after executing 'on_after_match' code. */

_119:
/* CONTINUE -- without executing 'on_after_match' (e.g. on FAILURE). */


    /* Mode change = another function takes over the analysis.
     * => After mode change the analyzer function needs to be quit!
     * ASSERT: 'CONTINUE' after mode change is not allowed.                   */
    __quex_assert(   me->DEBUG_analyzer_function_at_entry 
                  == me->current_analyzer_function);


    if( QUEX_NAME(TokenQueue_is_full)(&self._token_queue) ) {
        return;
    }


goto _120;

    __quex_assert_no_passage();

    /* Following labels are referenced in macros. It cannot be detected
     * whether the macros are applied in user code or not. To avoid compiler.
     * warnings of unused labels, they are referenced in unreachable code.   */
    goto _117; /* in RETURN                */
    goto _118; /* in CONTINUE              */
    goto _119; /* in CONTINUE and skippers */
#   if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
    goto _121; /* in QUEX_GOTO_STATE       */
#   endif

    /* Prevent compiler warning 'unused variable'.                           */
    (void)QUEX_LEXEME_NULL;
    /* target_state_index and target_state_else_index appear when 
     * QUEX_GOTO_STATE is used without computed goto-s.                      */
    (void)target_state_index;
    (void)target_state_else_index;

#   undef Lexeme
#   undef LexemeBegin
#   undef LexemeEnd
#   undef LexemeNull
#   undef LexemeL
#   undef CONVERTER
#   undef self
#   undef QUEX_LABEL_STATE_ROUTER
}
QUEX_NAMESPACE_MAIN_CLOSE


QUEX_NAMESPACE_MAIN_OPEN

bool
QUEX_NAME(user_constructor)(QUEX_TYPE_ANALYZER* me)
{
    (void)me;

    __quex_assert(QUEX_NAME(mode_db)[QUEX_NAME(ModeID_CONVERTER)]  == &(QUEX_NAME(CONVERTER)));


#define self  (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
/* START: User's constructor extensions _______________________________________*/

/* END: _______________________________________________________________________*/
#undef self
    return true;
}

void
QUEX_NAME(user_destructor)(QUEX_TYPE_ANALYZER* me)
{
    (void)me;

#define self  (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
/* START: User's constructor extensions _______________________________________*/

/* END: _______________________________________________________________________*/
#undef self
}

bool
QUEX_NAME(user_reset)(QUEX_TYPE_ANALYZER* me)
{
    (void)me;

#define self  (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
/* START: User's 'reset' ______________________________________________________*/

/* END: _______________________________________________________________________*/
#undef self
    return true;
}

void
QUEX_NAME(user_print)(QUEX_TYPE_ANALYZER* me)
{
    (void)me;

#define self  (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
/* START: User's constructor extensions _______________________________________*/

/* END: _______________________________________________________________________*/
#undef self
}

#ifdef QUEX_OPTION_INCLUDE_STACK

bool
QUEX_NAME(user_memento_pack)(QUEX_TYPE_ANALYZER* me, 
                             const char*         InputName, 
                             QUEX_NAME(Memento)* memento) 
{
    (void)me; (void)memento; (void)InputName;

#define self  (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
/* START: User's memento 'pack' _______________________________________________*/

/* END: _______________________________________________________________________*/
#undef self
    return true;
}

void
QUEX_NAME(user_memento_unpack)(QUEX_TYPE_ANALYZER*  me, 
                               QUEX_NAME(Memento)*  memento)
{
    (void)me; (void)memento;

#define self  (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
/* START: User's memento 'unpack' _____________________________________________*/

/* END: _______________________________________________________________________*/
#undef self
}
#endif /* QUEX_OPTION_INCLUDE_STACK */

QUEX_NAMESPACE_MAIN_CLOSE



#include "convjsonLexer-token"
QUEX_NAMESPACE_TOKEN_OPEN
QUEX_TYPE_LEXATOM   QUEX_NAME_TOKEN(LexemeNull) = (QUEX_TYPE_LEXATOM)0;
QUEX_NAMESPACE_TOKEN_CLOSE


