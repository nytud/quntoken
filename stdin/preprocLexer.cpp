
#include "preprocLexer"

#include <quex/code_base/analyzer/C-adaptions.h>
/* The file 'multi.i' contains implementations which are the same for all 
 * possibly generated analyzers. If QUEX_OPTION_MULTI is defined, it is
 * NOT supposed to be included here. If not--in which case we have a single
 * analzer--then it is included.                                             */
#include <quex/code_base/single.i>

QUEX_NAMESPACE_MAIN_OPEN
QUEX_NAME(Mode) QUEX_NAME(PREPROC) = {
    /* id                */ QUEX_NAME(ModeID_PREPROC),
    /* name              */ "PREPROC",
#   if      defined(QUEX_OPTION_INDENTATION_TRIGGER) \
       && ! defined(QUEX_OPTION_INDENTATION_DEFAULT_HANDLER)
    /* on_indentation    */ QUEX_NAME(Mode_on_indentation_null_function),
#   endif
    /* on_entry          */ QUEX_NAME(Mode_on_entry_exit_null_function),
    /* on_exit           */ QUEX_NAME(Mode_on_entry_exit_null_function),
#   if      defined(QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK)
    /* has_base          */ QUEX_NAME(PREPROC_has_base),
    /* has_entry_from    */ QUEX_NAME(PREPROC_has_entry_from),
    /* has_exit_to       */ QUEX_NAME(PREPROC_has_exit_to),
#   endif
    /* analyzer_function */ QUEX_NAME(PREPROC_analyzer_function)
};

QUEX_NAME(Mode)* (QUEX_NAME(mode_db)[__QUEX_SETTING_MAX_MODE_CLASS_N]) = {
    &QUEX_NAME(PREPROC)
};
#define self        (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
#define LexemeNull  (&QUEX_LEXEME_NULL)
#define RETURN      return

void
QUEX_NAME(PREPROC_on_entry)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* FromMode) {
    (void)me;
    (void)FromMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(PREPROC).has_entry_from(FromMode);
#   endif

}

void
QUEX_NAME(PREPROC_on_exit)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* ToMode)  {
    (void)me;
    (void)ToMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(PREPROC).has_exit_to(ToMode);
#   endif

}

#if defined(QUEX_OPTION_INDENTATION_TRIGGER) 
void
QUEX_NAME(PREPROC_on_indentation)(QUEX_TYPE_ANALYZER*    me, 
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
QUEX_NAME(PREPROC_has_base)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return false;
}
bool
QUEX_NAME(PREPROC_has_entry_from)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
switch( Mode->id ) {

    case QUEX_NAME(ModeID_PREPROC): {

    return true;
    }

    default: {

    return true;
    }

    }

}
bool
QUEX_NAME(PREPROC_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
switch( Mode->id ) {

    case QUEX_NAME(ModeID_PREPROC): {

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

/* #include "preprocLexer"*/
QUEX_NAMESPACE_MAIN_OPEN
#ifdef      QUEX_FUNCTION_COUNT_ARBITRARY
#   undef   QUEX_FUNCTION_COUNT_ARBITRARY
#endif
#ifdef      QUEX_OPTION_COUNTER
#    define QUEX_FUNCTION_COUNT_ARBITRARY(ME, BEGIN, END) \
            do {                              \
                QUEX_NAME(PREPROC_counter)((ME), (BEGIN), (END));     \
                __quex_debug_counter();       \
            } while(0)
#else
#    define QUEX_FUNCTION_COUNT_ARBITRARY(ME, BEGIN, END) /* empty */
#endif
#ifdef QUEX_OPTION_COUNTER
static void
QUEX_NAME(PREPROC_counter)(QUEX_TYPE_ANALYZER* me, QUEX_TYPE_LEXATOM* LexemeBegin, QUEX_TYPE_LEXATOM* LexemeEnd)
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

    /* (297272 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_14:
    __quex_debug("Init State\n");
    __quex_debug_state(297272);
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
    /* (297272 from 297276)  */
    goto _14;


    __quex_assert_no_passage();
_8:
    /* (DROP_OUT from 297275)  */
    goto _13;
_15:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_6:
    /* (DROP_OUT from 297273)  */
    goto _11;


    __quex_assert_no_passage();
_7:
    /* (DROP_OUT from 297274)  */
    goto _12;


    __quex_assert_no_passage();
_5:
    /* (DROP_OUT from 297272)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _16;
    goto _15;


    __quex_assert_no_passage();
_2:
    /* (297273 from 297272)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297273);
goto _6;


    __quex_assert_no_passage();
_3:
    /* (297274 from 297272)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297274);
goto _7;


    __quex_assert_no_passage();
_4:
    /* (297275 from 297272)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297275);
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
    __quex_debug("* TERMINAL <LOOP 1711>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_12:
    __quex_debug("* TERMINAL <LOOP 1712>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_13:
    __quex_debug("* TERMINAL <LOOP 1713>\n");
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
#define   CONTINUE do { goto _45; } while(0)

#ifdef    RETURN
#   undef RETURN
#endif
#define   RETURN   do { goto _44; } while(0)

__QUEX_TYPE_ANALYZER_RETURN_VALUE  
QUEX_NAME(PREPROC_analyzer_function)(QUEX_TYPE_ANALYZER* me) 
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
#   define QUEX_LABEL_STATE_ROUTER _48
#   define PREPROC    (QUEX_NAME(PREPROC))

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
_47:
    me->buffer._lexeme_start_p = me->buffer._read_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);
_9:
    /* (297265 from RELOAD_FORWARD) (297265 from BEFORE_ENTRY)  */

    input = *(me->buffer._read_p);


    __quex_debug("Init State\n");
    __quex_debug_state(297265);
if( input < 0x2150 ) {
if( input < 0x530 ) {
if( input < 0x20 ) {
switch( input ) {
case 0x0: goto _19;
case 0x2: case 0x3: case 0x4: case 0x5: case 0x6: case 0x7: case 0x8: goto _10;
case 0x9: goto _11;
case 0xA: goto _12;
case 0xB: case 0xC: case 0xD: goto _13;
case 0xE: case 0xF: 
case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: 
case 0x18: case 0x19: case 0x1A: case 0x1B: case 0x1C: case 0x1D: case 0x1E: case 0x1F: goto _10;
default: goto _15;
}
} else {
switch( input ) {
case 0x7F: case 0x80: case 0x81: case 0x82: case 0x83: case 0x84: goto _10;
case 0x85: goto _13;
case 0x86: case 0x87: 
case 0x88: case 0x89: case 0x8A: case 0x8B: case 0x8C: case 0x8D: case 0x8E: case 0x8F: 
case 0x90: case 0x91: case 0x92: case 0x93: case 0x94: case 0x95: case 0x96: case 0x97: 
case 0x98: case 0x99: case 0x9A: case 0x9B: case 0x9C: case 0x9D: case 0x9E: case 0x9F: 
case 0xAD: 
case 0x250: case 0x251: case 0x252: case 0x253: case 0x254: case 0x255: case 0x256: case 0x257: 
case 0x258: case 0x259: case 0x25A: case 0x25B: case 0x25C: case 0x25D: case 0x25E: case 0x25F: 
case 0x260: case 0x261: case 0x262: case 0x263: case 0x264: case 0x265: case 0x266: case 0x267: 
case 0x268: case 0x269: case 0x26A: case 0x26B: case 0x26C: case 0x26D: case 0x26E: case 0x26F: 
case 0x270: case 0x271: case 0x272: case 0x273: case 0x274: case 0x275: case 0x276: case 0x277: 
case 0x278: case 0x279: case 0x27A: case 0x27B: case 0x27C: case 0x27D: case 0x27E: case 0x27F: 
case 0x280: case 0x281: case 0x282: case 0x283: case 0x284: case 0x285: case 0x286: case 0x287: 
case 0x288: case 0x289: case 0x28A: case 0x28B: case 0x28C: case 0x28D: case 0x28E: case 0x28F: 
case 0x290: case 0x291: case 0x292: case 0x293: case 0x294: case 0x295: case 0x296: case 0x297: 
case 0x298: case 0x299: case 0x29A: case 0x29B: case 0x29C: case 0x29D: case 0x29E: case 0x29F: 
case 0x2A0: case 0x2A1: case 0x2A2: case 0x2A3: case 0x2A4: case 0x2A5: case 0x2A6: case 0x2A7: 
case 0x2A8: case 0x2A9: case 0x2AA: case 0x2AB: case 0x2AC: case 0x2AD: case 0x2AE: case 0x2AF: goto _10;
default: goto _11;
}
}
} else {
if( input < 0x2028 ) {
if( input < 0x1E00 ) {
if     ( input < 0x1680 )   goto _10;
else if( input == 0x1680 )  goto _11;
else if( input < 0x1D00 )   goto _10;
else                        goto _11;
} else {
if     ( input < 0x1F00 )  goto _10;
else if( input < 0x200B )  goto _11;
else if( input < 0x2010 )  goto _10;
else                       goto _11;
}
} else {
switch( input ) {
case 0x2028: case 0x2029: goto _13;
case 0x202A: case 0x202B: case 0x202C: case 0x202D: case 0x202E: 
case 0x2060: case 0x2061: case 0x2062: case 0x2063: case 0x2064: 
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
case 0x20F8: case 0x20F9: case 0x20FA: case 0x20FB: case 0x20FC: case 0x20FD: case 0x20FE: case 0x20FF: goto _10;
default: goto _11;
}
}
}
} else {
if( input < 0xFB00 ) {
if( input < 0x2C00 ) {
if( input < 0x2700 ) {
if     ( input < 0x2190 )  goto _10;
else if( input < 0x2400 )  goto _11;
else if( input < 0x25A0 )  goto _10;
else                       goto _11;
} else {
if     ( input < 0x27C0 )  goto _10;
else if( input < 0x2800 )  goto _11;
else if( input < 0x2900 )  goto _10;
else                       goto _11;
}
} else {
if( input < 0x2E80 ) {
if     ( input < 0x2C60 )  goto _10;
else if( input < 0x2C80 )  goto _11;
else if( input < 0x2E00 )  goto _10;
else                       goto _11;
} else {
if     ( input < 0x3000 )   goto _10;
else if( input == 0x3000 )  goto _11;
else if( input < 0xA720 )   goto _10;
else if( input < 0xA800 )   goto _11;
else                        goto _10;
}
}
} else {
if( input < 0x1D100 ) {
switch( input ) {
case 0xFB00: case 0xFB01: case 0xFB02: case 0xFB03: case 0xFB04: case 0xFB05: case 0xFB06: case 0xFB07: 
case 0xFB08: case 0xFB09: case 0xFB0A: case 0xFB0B: case 0xFB0C: case 0xFB0D: case 0xFB0E: case 0xFB0F: 
case 0xFB10: case 0xFB11: case 0xFB12: case 0xFB13: case 0xFB14: case 0xFB15: case 0xFB16: case 0xFB17: 
case 0xFB18: case 0xFB19: case 0xFB1A: case 0xFB1B: case 0xFB1C: case 0xFB1D: case 0xFB1E: case 0xFB1F: 
case 0xFB20: case 0xFB21: case 0xFB22: case 0xFB23: case 0xFB24: case 0xFB25: case 0xFB26: case 0xFB27: 
case 0xFB28: case 0xFB29: case 0xFB2A: case 0xFB2B: case 0xFB2C: case 0xFB2D: case 0xFB2E: case 0xFB2F: 
case 0xFB30: case 0xFB31: case 0xFB32: case 0xFB33: case 0xFB34: case 0xFB35: case 0xFB36: case 0xFB37: 
case 0xFB38: case 0xFB39: case 0xFB3A: case 0xFB3B: case 0xFB3C: case 0xFB3D: case 0xFB3E: case 0xFB3F: 
case 0xFB40: case 0xFB41: case 0xFB42: case 0xFB43: case 0xFB44: case 0xFB45: case 0xFB46: case 0xFB47: 
case 0xFB48: case 0xFB49: case 0xFB4A: case 0xFB4B: case 0xFB4C: case 0xFB4D: case 0xFB4E: case 0xFB4F: 
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
case 0x10188: case 0x10189: case 0x1018A: case 0x1018B: case 0x1018C: case 0x1018D: case 0x1018E: case 0x1018F: goto _11;
default: goto _10;
}
} else {
if( input < 0x1D400 ) {
if     ( input < 0x1D173 )  goto _11;
else if( input < 0x1D17B )  goto _10;
else if( input < 0x1D200 )  goto _11;
else                        goto _10;
} else {
if     ( input < 0x1D800 )   goto _11;
else if( input < 0x1F600 )   goto _10;
else if( input < 0x1F916 )   goto _11;
else if( input < 0x110000 )  goto _10;
else                         goto _15;
}
}
}
}


    __quex_assert_no_passage();
_17:
    /* (DROP_OUT from 297270) (DROP_OUT from 297267)  */

    goto _0;
_30:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_16:
    /* (DROP_OUT from 297266)  */
    goto _2;


    __quex_assert_no_passage();
_18:
    /* (DROP_OUT from 297269) (DROP_OUT from 297268)  */
    goto _1;


    __quex_assert_no_passage();
_15:
    /* (DROP_OUT from 297265)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _7;
    goto _30;


    __quex_assert_no_passage();
_10:
    /* (297266 from 297265)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(297266);
goto _16;


    __quex_assert_no_passage();
_11:
    /* (297267 from 297265)  */
    ++(me->buffer._read_p);

_34:
    input = *(me->buffer._read_p);


    __quex_debug_state(297267);
if( input < 0x2400 ) {
if( input < 0x1D00 ) {
if( input < 0xA0 ) {
switch( input ) {
case 0x0: goto _21;
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
case 0x78: case 0x79: case 0x7A: case 0x7B: case 0x7C: case 0x7D: case 0x7E: goto _14;
default: goto _17;
}
} else {
if( input < 0x2B0 ) {
if     ( input < 0xAD )   goto _14;
else if( input == 0xAD )  goto _17;
else if( input < 0x250 )  goto _14;
else                      goto _17;
} else {
if     ( input < 0x530 )    goto _14;
else if( input < 0x1680 )   goto _17;
else if( input == 0x1680 )  goto _14;
else                        goto _17;
}
}
} else {
if( input < 0x2060 ) {
if( input < 0x200B ) {
if     ( input < 0x1E00 )  goto _14;
else if( input < 0x1F00 )  goto _17;
else                       goto _14;
} else {
if     ( input < 0x2010 )  goto _17;
else if( input < 0x2028 )  goto _14;
else if( input < 0x202F )  goto _17;
else                       goto _14;
}
} else {
switch( input ) {
case 0x2060: case 0x2061: case 0x2062: case 0x2063: case 0x2064: 
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
case 0x2188: case 0x2189: case 0x218A: case 0x218B: case 0x218C: case 0x218D: case 0x218E: case 0x218F: goto _17;
default: goto _14;
}
}
}
} else {
if( input < 0xFB00 ) {
if( input < 0x2C60 ) {
if( input < 0x27C0 ) {
if     ( input < 0x25A0 )  goto _17;
else if( input < 0x2700 )  goto _14;
else                       goto _17;
} else {
if     ( input < 0x2800 )  goto _14;
else if( input < 0x2900 )  goto _17;
else if( input < 0x2C00 )  goto _14;
else                       goto _17;
}
} else {
if( input < 0x3000 ) {
if     ( input < 0x2C80 )  goto _14;
else if( input < 0x2E00 )  goto _17;
else if( input < 0x2E80 )  goto _14;
else                       goto _17;
} else {
if     ( input == 0x3000 )  goto _14;
else if( input < 0xA720 )   goto _17;
else if( input < 0xA800 )   goto _14;
else                        goto _17;
}
}
} else {
if( input < 0x1D100 ) {
switch( input ) {
case 0xFB00: case 0xFB01: case 0xFB02: case 0xFB03: case 0xFB04: case 0xFB05: case 0xFB06: case 0xFB07: 
case 0xFB08: case 0xFB09: case 0xFB0A: case 0xFB0B: case 0xFB0C: case 0xFB0D: case 0xFB0E: case 0xFB0F: 
case 0xFB10: case 0xFB11: case 0xFB12: case 0xFB13: case 0xFB14: case 0xFB15: case 0xFB16: case 0xFB17: 
case 0xFB18: case 0xFB19: case 0xFB1A: case 0xFB1B: case 0xFB1C: case 0xFB1D: case 0xFB1E: case 0xFB1F: 
case 0xFB20: case 0xFB21: case 0xFB22: case 0xFB23: case 0xFB24: case 0xFB25: case 0xFB26: case 0xFB27: 
case 0xFB28: case 0xFB29: case 0xFB2A: case 0xFB2B: case 0xFB2C: case 0xFB2D: case 0xFB2E: case 0xFB2F: 
case 0xFB30: case 0xFB31: case 0xFB32: case 0xFB33: case 0xFB34: case 0xFB35: case 0xFB36: case 0xFB37: 
case 0xFB38: case 0xFB39: case 0xFB3A: case 0xFB3B: case 0xFB3C: case 0xFB3D: case 0xFB3E: case 0xFB3F: 
case 0xFB40: case 0xFB41: case 0xFB42: case 0xFB43: case 0xFB44: case 0xFB45: case 0xFB46: case 0xFB47: 
case 0xFB48: case 0xFB49: case 0xFB4A: case 0xFB4B: case 0xFB4C: case 0xFB4D: case 0xFB4E: case 0xFB4F: 
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
case 0x10188: case 0x10189: case 0x1018A: case 0x1018B: case 0x1018C: case 0x1018D: case 0x1018E: case 0x1018F: goto _14;
default: goto _17;
}
} else {
if( input < 0x1D400 ) {
if     ( input < 0x1D173 )  goto _14;
else if( input < 0x1D17B )  goto _17;
else if( input < 0x1D200 )  goto _14;
else                        goto _17;
} else {
if     ( input < 0x1D800 )  goto _14;
else if( input < 0x1F600 )  goto _17;
else if( input < 0x1F916 )  goto _14;
else                        goto _17;
}
}
}
}


    __quex_assert_no_passage();
_20:
    /* (297267 from RELOAD_FORWARD)  */
    goto _34;


    __quex_assert_no_passage();
_12:
    /* (297268 from 297269) (297268 from 297268) (297268 from 297265)  */

    ++(me->buffer._read_p);

_37:
    input = *(me->buffer._read_p);


    __quex_debug_state(297268);
switch( input ) {
case 0x0: goto _23;
case 0xA: case 0xB: case 0xC: case 0xD: 
case 0x85: 
case 0x2028: case 0x2029: goto _12;
default: goto _18;
}


    __quex_assert_no_passage();
_22:
    /* (297268 from RELOAD_FORWARD)  */
    goto _37;


    __quex_assert_no_passage();
_24:
    /* (297269 from RELOAD_FORWARD)  */
_39:
    input = *(me->buffer._read_p);


    __quex_debug_state(297269);
switch( input ) {
case 0x0: goto _25;
case 0xA: case 0xB: case 0xC: case 0xD: 
case 0x85: 
case 0x2028: case 0x2029: goto _12;
default: goto _18;
}


    __quex_assert_no_passage();
_13:
    /* (297269 from 297265)  */
    ++(me->buffer._read_p);

    goto _39;


    __quex_assert_no_passage();
_14:
    /* (297270 from 297267) (297270 from 297270)  */

    ++(me->buffer._read_p);

_42:
    input = *(me->buffer._read_p);


    __quex_debug_state(297270);
if( input < 0x2400 ) {
if( input < 0x1D00 ) {
if( input < 0xA0 ) {
switch( input ) {
case 0x0: goto _27;
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
case 0x78: case 0x79: case 0x7A: case 0x7B: case 0x7C: case 0x7D: case 0x7E: goto _14;
default: goto _17;
}
} else {
if( input < 0x2B0 ) {
if     ( input < 0xAD )   goto _14;
else if( input == 0xAD )  goto _17;
else if( input < 0x250 )  goto _14;
else                      goto _17;
} else {
if     ( input < 0x530 )    goto _14;
else if( input < 0x1680 )   goto _17;
else if( input == 0x1680 )  goto _14;
else                        goto _17;
}
}
} else {
if( input < 0x2060 ) {
if( input < 0x200B ) {
if     ( input < 0x1E00 )  goto _14;
else if( input < 0x1F00 )  goto _17;
else                       goto _14;
} else {
if     ( input < 0x2010 )  goto _17;
else if( input < 0x2028 )  goto _14;
else if( input < 0x202F )  goto _17;
else                       goto _14;
}
} else {
switch( input ) {
case 0x2060: case 0x2061: case 0x2062: case 0x2063: case 0x2064: 
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
case 0x2188: case 0x2189: case 0x218A: case 0x218B: case 0x218C: case 0x218D: case 0x218E: case 0x218F: goto _17;
default: goto _14;
}
}
}
} else {
if( input < 0xFB00 ) {
if( input < 0x2C60 ) {
if( input < 0x27C0 ) {
if     ( input < 0x25A0 )  goto _17;
else if( input < 0x2700 )  goto _14;
else                       goto _17;
} else {
if     ( input < 0x2800 )  goto _14;
else if( input < 0x2900 )  goto _17;
else if( input < 0x2C00 )  goto _14;
else                       goto _17;
}
} else {
if( input < 0x3000 ) {
if     ( input < 0x2C80 )  goto _14;
else if( input < 0x2E00 )  goto _17;
else if( input < 0x2E80 )  goto _14;
else                       goto _17;
} else {
if     ( input == 0x3000 )  goto _14;
else if( input < 0xA720 )   goto _17;
else if( input < 0xA800 )   goto _14;
else                        goto _17;
}
}
} else {
if( input < 0x1D100 ) {
switch( input ) {
case 0xFB00: case 0xFB01: case 0xFB02: case 0xFB03: case 0xFB04: case 0xFB05: case 0xFB06: case 0xFB07: 
case 0xFB08: case 0xFB09: case 0xFB0A: case 0xFB0B: case 0xFB0C: case 0xFB0D: case 0xFB0E: case 0xFB0F: 
case 0xFB10: case 0xFB11: case 0xFB12: case 0xFB13: case 0xFB14: case 0xFB15: case 0xFB16: case 0xFB17: 
case 0xFB18: case 0xFB19: case 0xFB1A: case 0xFB1B: case 0xFB1C: case 0xFB1D: case 0xFB1E: case 0xFB1F: 
case 0xFB20: case 0xFB21: case 0xFB22: case 0xFB23: case 0xFB24: case 0xFB25: case 0xFB26: case 0xFB27: 
case 0xFB28: case 0xFB29: case 0xFB2A: case 0xFB2B: case 0xFB2C: case 0xFB2D: case 0xFB2E: case 0xFB2F: 
case 0xFB30: case 0xFB31: case 0xFB32: case 0xFB33: case 0xFB34: case 0xFB35: case 0xFB36: case 0xFB37: 
case 0xFB38: case 0xFB39: case 0xFB3A: case 0xFB3B: case 0xFB3C: case 0xFB3D: case 0xFB3E: case 0xFB3F: 
case 0xFB40: case 0xFB41: case 0xFB42: case 0xFB43: case 0xFB44: case 0xFB45: case 0xFB46: case 0xFB47: 
case 0xFB48: case 0xFB49: case 0xFB4A: case 0xFB4B: case 0xFB4C: case 0xFB4D: case 0xFB4E: case 0xFB4F: 
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
case 0x10188: case 0x10189: case 0x1018A: case 0x1018B: case 0x1018C: case 0x1018D: case 0x1018E: case 0x1018F: goto _14;
default: goto _17;
}
} else {
if( input < 0x1D400 ) {
if     ( input < 0x1D173 )  goto _14;
else if( input < 0x1D17B )  goto _17;
else if( input < 0x1D200 )  goto _14;
else                        goto _17;
} else {
if     ( input < 0x1D800 )  goto _14;
else if( input < 0x1F600 )  goto _17;
else if( input < 0x1F916 )  goto _14;
else                        goto _17;
}
}
}
}


    __quex_assert_no_passage();
_26:
    /* (297270 from RELOAD_FORWARD)  */
    goto _42;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_3:
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
_4:
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
_5:
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
_6:
    __quex_debug("* TERMINAL END_OF_STREAM\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 23 "preproc.qx"
self_send(preproc_TERMINATION);

__QUEX_PURE_RETURN;


#   line 1023 "preprocLexer.cpp"

}
    /* End of Stream FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
__QUEX_PURE_RETURN;
_7:
    __quex_debug("* TERMINAL FAILURE\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 21 "preproc.qx"
self_send(preproc_TERMINATION);

__QUEX_PURE_RETURN;


#   line 1041 "preprocLexer.cpp"

}
RETURN;
_8:
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
    __quex_debug("* TERMINAL [: difference( union({BASE_CLASS}, {SPACE}), {NEWLINECHAR}) :]+\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 10 "preproc.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(preproc_BASECHARS);

__QUEX_PURE_RETURN;


#   line 1070 "preprocLexer.cpp"

}
RETURN;
_1:
    __quex_debug("* TERMINAL {NEWLINECHAR}+\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 11 "preproc.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(preproc_BASECHARS);

__QUEX_PURE_RETURN;


#   line 1086 "preprocLexer.cpp"

}
RETURN;
_2:
    __quex_debug("* TERMINAL .\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
QUEX_LEXEME_TERMINATING_ZERO_SET(&me->buffer);
{

#   line 14 "preproc.qx"

        std::cerr << "invalid character ("
                  << self.line_number() << ","
                  << self.column_number() << "): "
                  << QUEX_CONVERTER_STRING(unicode, char)(Lexeme) << std::endl;
        self_send1(preproc_REPLACEMENTCHAR, self.REPLACEMENTCHAR_CPP.c_str());
    

#   line 1105 "preprocLexer.cpp"

}
RETURN;
if(0) {
    /* Avoid unreferenced labels. */
    goto _3;
    goto _4;
    goto _5;
    goto _6;
    goto _7;
    goto _8;
    goto _0;
    goto _1;
    goto _2;
}
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
_48:
switch( target_state_index ) {
case 6: {
goto _6;}
case 9: {
goto _9;}
case 17: {
goto _17;}
case 18: {
goto _18;}
case 20: {
goto _20;}
case 22: {
goto _22;}
case 24: {
goto _24;}
case 26: {
goto _26;}
default: {
goto _26;}
}
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */


    __quex_assert_no_passage();
_19:
    /* (RELOAD_FORWARD from 297265)  */
    target_state_index = QUEX_LABEL(9); target_state_else_index = QUEX_LABEL(6);

_43:

    __quex_debug3("RELOAD_FORWARD: success->%i; failure->%i", 
                  (int)target_state_index, (int)target_state_else_index);
    __quex_assert(*(me->buffer._read_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    
    __quex_debug_reload_before();                 
    load_result = QUEX_NAME(Buffer_load_forward)(&me->buffer, (QUEX_TYPE_LEXATOM**)position, PositionRegisterN);
    __quex_debug_reload_after(load_result);

    switch( load_result ) {
    case E_LoadResult_DONE:              QUEX_GOTO_STATE(target_state_index);      
    case E_LoadResult_BAD_LEXATOM:       goto _3;
    case E_LoadResult_FAILURE:           goto _4;
    case E_LoadResult_NO_SPACE_FOR_LOAD: goto _5;
    case E_LoadResult_NO_MORE_DATA:      QUEX_GOTO_STATE(target_state_else_index); 
    default:                             __quex_assert(false);
    }


    __quex_assert_no_passage();
_21:
    /* (RELOAD_FORWARD from 297267)  */
    target_state_index = QUEX_LABEL(20); target_state_else_index = QUEX_LABEL(17);

    goto _43;


    __quex_assert_no_passage();
_23:
    /* (RELOAD_FORWARD from 297268)  */
    target_state_index = QUEX_LABEL(22); target_state_else_index = QUEX_LABEL(18);

    goto _43;


    __quex_assert_no_passage();
_25:
    /* (RELOAD_FORWARD from 297269)  */
    target_state_index = QUEX_LABEL(24); target_state_else_index = QUEX_LABEL(18);

    goto _43;


    __quex_assert_no_passage();
_27:
    /* (RELOAD_FORWARD from 297270)  */
    target_state_index = QUEX_LABEL(26); target_state_else_index = QUEX_LABEL(17);

    goto _43;

_44:
/* RETURN -- after executing 'on_after_match' code. */
    __QUEX_PURE_RETURN;


_45:
/* CONTINUE -- after executing 'on_after_match' code. */

_46:
/* CONTINUE -- without executing 'on_after_match' (e.g. on FAILURE). */


    /* Mode change = another function takes over the analysis.
     * => After mode change the analyzer function needs to be quit!
     * ASSERT: 'CONTINUE' after mode change is not allowed.                   */
    __quex_assert(   me->DEBUG_analyzer_function_at_entry 
                  == me->current_analyzer_function);


    if( QUEX_NAME(TokenQueue_is_full)(&self._token_queue) ) {
        return;
    }


goto _47;

    __quex_assert_no_passage();

    /* Following labels are referenced in macros. It cannot be detected
     * whether the macros are applied in user code or not. To avoid compiler.
     * warnings of unused labels, they are referenced in unreachable code.   */
    goto _44; /* in RETURN                */
    goto _45; /* in CONTINUE              */
    goto _46; /* in CONTINUE and skippers */
#   if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
    goto _48; /* in QUEX_GOTO_STATE       */
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
#   undef PREPROC
#   undef self
#   undef QUEX_LABEL_STATE_ROUTER
}
QUEX_NAMESPACE_MAIN_CLOSE


QUEX_NAMESPACE_MAIN_OPEN

bool
QUEX_NAME(user_constructor)(QUEX_TYPE_ANALYZER* me)
{
    (void)me;

    __quex_assert(QUEX_NAME(mode_db)[QUEX_NAME(ModeID_PREPROC)]  == &(QUEX_NAME(PREPROC)));


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



#include "preprocLexer-token"
QUEX_NAMESPACE_TOKEN_OPEN
QUEX_TYPE_LEXATOM   QUEX_NAME_TOKEN(LexemeNull) = (QUEX_TYPE_LEXATOM)0;
QUEX_NAMESPACE_TOKEN_CLOSE


