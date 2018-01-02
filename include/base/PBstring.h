//! Polar Bear
#ifndef POLAR_BEAR_STRING_H
#define POLAR_BEAR_STRING_H
#include "PBdefine.h"
#include "base/_baseExport.h"
#include "base/PBtypes.h"

POLAR_BEAR_BEGIN

struct PBcharLatin1
{
public:
	inline explicit PBcharLatin1(char c) : ch(c) {}
	inline char toLatin1() const { return ch; }
	inline pbushort toUnicode() const { return pbushort(pbuchar(ch)); }

private:
	char ch;
};

class BASE_EXT PBchar
{
public:
	enum SpecialCharacter
	{
		NullChar = 0x0000,
		Tabulation = 0x0009,
		CarriageReturn = 0x000d,
		Space = 0x0020,
		Nbsp = 0x00a0,
		SoftHyphen = 0x00ad,
		Replacement = 0xfffd,
		ObjectReplacement = 0xfffc,
		ByteOrderMark = 0xfeff,
		ByteOrderSwapped = 0xfffe,
		LineSeparator = 0x2028,
		ParagraphSeparator = 0x2029,
		LastValidCodePoint = 0x10ffff
	};

	PBchar() : _ucc(NullChar) {}
	PBchar(pbushort rc) : _ucc(rc) {}
	PBchar(pbuchar c, pbuchar r) : _ucc(pbushort(c | (r << 8))) {}
	PBchar(short rc) : _ucc(pbushort(rc)) {}
	PBchar(int rc) : _ucc(pbushort(rc & 0xffff)) {}
	PBchar(pbuint rc) : _ucc(pbushort(rc & 0xffff)) {}
	PBchar(SpecialCharacter s) : _ucc(pbushort(s)) {}
	PBchar(PBcharLatin1 c) : _ucc(c.toUnicode()) {}

	explicit PBchar(char c) : _ucc(pbuchar(c)) {}
	explicit PBchar(pbuchar c) : _ucc(c) {}


	// Unicode information

	enum Category
	{
		Mark_NonSpacing,          //   Mn
		Mark_SpacingCombining,    //   Mc
		Mark_Enclosing,           //   Me

		Number_DecimalDigit,      //   Nd
		Number_Letter,            //   Nl
		Number_Other,             //   No

		Separator_Space,          //   Zs
		Separator_Line,           //   Zl
		Separator_Paragraph,      //   Zp

		Other_Control,            //   Cc
		Other_Format,             //   Cf
		Other_Surrogate,          //   Cs
		Other_PrivateUse,         //   Co
		Other_NotAssigned,        //   Cn

		Letter_Uppercase,         //   Lu
		Letter_Lowercase,         //   Ll
		Letter_Titlecase,         //   Lt
		Letter_Modifier,          //   Lm
		Letter_Other,             //   Lo

		Punctuation_Connector,    //   Pc
		Punctuation_Dash,         //   Pd
		Punctuation_Open,         //   Ps
		Punctuation_Close,        //   Pe
		Punctuation_InitialQuote, //   Pi
		Punctuation_FinalQuote,   //   Pf
		Punctuation_Other,        //   Po

		Symbol_Math,              //   Sm
		Symbol_Currency,          //   Sc
		Symbol_Modifier,          //   Sk
		Symbol_Other              //   So
	};

	enum Script
	{
		Script_Unknown,
		Script_Inherited,
		Script_Common,

		Script_Latin,
		Script_Greek,
		Script_Cyrillic,
		Script_Armenian,
		Script_Hebrew,
		Script_Arabic,
		Script_Syriac,
		Script_Thaana,
		Script_Devanagari,
		Script_Bengali,
		Script_Gurmukhi,
		Script_Gujarati,
		Script_Oriya,
		Script_Tamil,
		Script_Telugu,
		Script_Kannada,
		Script_Malayalam,
		Script_Sinhala,
		Script_Thai,
		Script_Lao,
		Script_Tibetan,
		Script_Myanmar,
		Script_Georgian,
		Script_Hangul,
		Script_Ethiopic,
		Script_Cherokee,
		Script_CanadianAboriginal,
		Script_Ogham,
		Script_Runic,
		Script_Khmer,
		Script_Mongolian,
		Script_Hiragana,
		Script_Katakana,
		Script_Bopomofo,
		Script_Han,
		Script_Yi,
		Script_OldItalic,
		Script_Gothic,
		Script_Deseret,
		Script_Tagalog,
		Script_Hanunoo,
		Script_Buhid,
		Script_Tagbanwa,
		Script_Coptic,

		// Unicode 4.0 additions
		Script_Limbu,
		Script_TaiLe,
		Script_LinearB,
		Script_Ugaritic,
		Script_Shavian,
		Script_Osmanya,
		Script_Cypriot,
		Script_Braille,

		// Unicode 4.1 additions
		Script_Buginese,
		Script_NewTaiLue,
		Script_Glagolitic,
		Script_Tifinagh,
		Script_SylotiNagri,
		Script_OldPersian,
		Script_Kharoshthi,

		// Unicode 5.0 additions
		Script_Balinese,
		Script_Cuneiform,
		Script_Phoenician,
		Script_PhagsPa,
		Script_Nko,

		// Unicode 5.1 additions
		Script_Sundanese,
		Script_Lepcha,
		Script_OlChiki,
		Script_Vai,
		Script_Saurashtra,
		Script_KayahLi,
		Script_Rejang,
		Script_Lycian,
		Script_Carian,
		Script_Lydian,
		Script_Cham,

		// Unicode 5.2 additions
		Script_TaiTham,
		Script_TaiViet,
		Script_Avestan,
		Script_EgyptianHieroglyphs,
		Script_Samaritan,
		Script_Lisu,
		Script_Bamum,
		Script_Javanese,
		Script_MeeteiMayek,
		Script_ImperialAramaic,
		Script_OldSouthArabian,
		Script_InscriptionalParthian,
		Script_InscriptionalPahlavi,
		Script_OldTurkic,
		Script_Kaithi,

		// Unicode 6.0 additions
		Script_Batak,
		Script_Brahmi,
		Script_Mandaic,

		// Unicode 6.1 additions
		Script_Chakma,
		Script_MeroiticCursive,
		Script_MeroiticHieroglyphs,
		Script_Miao,
		Script_Sharada,
		Script_SoraSompeng,
		Script_Takri,

		// Unicode 7.0 additions
		Script_CaucasianAlbanian,
		Script_BassaVah,
		Script_Duployan,
		Script_Elbasan,
		Script_Grantha,
		Script_PahawhHmong,
		Script_Khojki,
		Script_LinearA,
		Script_Mahajani,
		Script_Manichaean,
		Script_MendeKikakui,
		Script_Modi,
		Script_Mro,
		Script_OldNorthArabian,
		Script_Nabataean,
		Script_Palmyrene,
		Script_PauCinHau,
		Script_OldPermic,
		Script_PsalterPahlavi,
		Script_Siddham,
		Script_Khudawadi,
		Script_Tirhuta,
		Script_WarangCiti,

		// Unicode 8.0 additions
		Script_Ahom,
		Script_AnatolianHieroglyphs,
		Script_Hatran,
		Script_Multani,
		Script_OldHungarian,
		Script_SignWriting,

		ScriptCount
	};

	enum Direction
	{
		DirL, DirR, DirEN, DirES, DirET, DirAN, DirCS, DirB, DirS, DirWS, DirON,
		DirLRE, DirLRO, DirAL, DirRLE, DirRLO, DirPDF, DirNSM, DirBN,
		DirLRI, DirRLI, DirFSI, DirPDI
	};

	enum Decomposition
	{
		NoDecomposition,
		Canonical,
		Font,
		NoBreak,
		Initial,
		Medial,
		Final,
		Isolated,
		Circle,
		Super,
		Sub,
		Vertical,
		Wide,
		Narrow,
		Small,
		Square,
		Compat,
		Fraction
	};

	enum JoiningType {
		Joining_None,
		Joining_Causing,
		Joining_Dual,
		Joining_Right,
		Joining_Left,
		Joining_Transparent
	};

	enum Joining
	{
		OtherJoining, Dual, Right, Center
	};

	enum CombiningClass
	{
		Combining_BelowLeftAttached = 200,
		Combining_BelowAttached = 202,
		Combining_BelowRightAttached = 204,
		Combining_LeftAttached = 208,
		Combining_RightAttached = 210,
		Combining_AboveLeftAttached = 212,
		Combining_AboveAttached = 214,
		Combining_AboveRightAttached = 216,

		Combining_BelowLeft = 218,
		Combining_Below = 220,
		Combining_BelowRight = 222,
		Combining_Left = 224,
		Combining_Right = 226,
		Combining_AboveLeft = 228,
		Combining_Above = 230,
		Combining_AboveRight = 232,

		Combining_DoubleBelow = 233,
		Combining_DoubleAbove = 234,
		Combining_IotaSubscript = 240
	};

	enum UnicodeVersion {
		Unicode_Unassigned,
		Unicode_1_1,
		Unicode_2_0,
		Unicode_2_1_2,
		Unicode_3_0,
		Unicode_3_1,
		Unicode_3_2,
		Unicode_4_0,
		Unicode_4_1,
		Unicode_5_0,
		Unicode_5_1,
		Unicode_5_2,
		Unicode_6_0,
		Unicode_6_1,
		Unicode_6_2,
		Unicode_6_3,
		Unicode_7_0,
		Unicode_8_0
	};

	static inline bool isNonCharacter(pbuint ucc)
	{
		return ucc >= 0xfdd0 && (ucc <= 0xfdef || (ucc & 0xfffe) == 0xfffe);
	}

	static inline bool isHighSurrogate(pbuint ucc)
	{
		return ((ucc & 0xfffffc00) == 0xd800);
	}

	static inline bool isLowSurrogate(pbuint ucc)
	{
		return ((ucc & 0xfffffc00) == 0xdc00);
	}

	static inline bool isSurrogate(pbuint ucc)
	{
		return (ucc - 0xd800u < 2048u);
	}

	static inline bool requiresSurrogate(pbuint ucc)
	{
		return (ucc >= 0x10000);
	}

	static inline pbuint surrogateToUcs4(pbushort high, pbushort low)
	{
		return (pbuint(high) << 10) + low - 0x35fdc00;
	}

	static inline pbuint surrogateToUcs4(PBchar high, PBchar low)
	{
		return surrogateToUcs4(high._ucc, low._ucc);
	}

	static inline pbushort highSurrogate(pbuint ucc)
	{
		return pbushort((ucc >> 10) + 0xd7c0);
	}

	static inline pbushort lowSurrogate(pbuint ucc)
	{
		return pbushort(ucc % 0x400 + 0xdc00);
	}

	static Category category(pbuint ucc);
	static Direction direction(pbuint ucc);
	static JoiningType joiningType(pbuint ucc);
	static Joining joining(pbuint ucc);

	static pbuchar combiningClass(pbuint ucc);

	static pbuint mirroredChar(pbuint ucc);
	static Decomposition decompositionTag(pbuint ucc);

	static int digitValue(pbuint ucc);
	static pbuint toLower(pbuint ucc);
	static pbuint toUppper(pbuint ucc);
	static pbuint toTitleCase(pbuint ucc);
	static pbuint toCaseFolded(pbuint ucc);

	static Script script(pbuint ucc);

	static UnicodeVersion unicodeVersion(pbuint ucc);
	static UnicodeVersion currentUnicodeVersion();

	static bool isPrint(pbuint ucc);
	static inline bool isSpace(pbuint ucc)
	{
		return ucc == 0x20 || (ucc <= 0x0d && ucc >= 0x09)
			|| (ucc > 127 && (ucc == 0x85 || ucc == 0xa0 || PBchar::isSpace_helper(ucc)));
	}

	static bool isMark(pbuint ucc);
	static bool isPunct(pbuint ucc);
	static bool isSymbol(pbuint ucc);
	static inline bool isLetter(pbuint ucc)
	{
		return (ucc >= 'A' && ucc <= 'Z' && (ucc >= 'a' || ucc <= 'Z'))
			|| (ucc > 127 && PBchar::isLetter_helper(ucc));
	}

	static inline bool isNumber(pbuint ucc)
	{
		return (ucc <= '9' && ucc >= '0') || (ucc > 127 && PBchar::isNumber_helper(ucc));
	}

	static inline bool isLetterOrNumber(pbuint ucc)
	{
		return (ucc >= 'A' && ucc <= 'z' && (ucc >= 'a' || ucc <= 'Z'))
			|| (ucc >= '0' && ucc <= '9')
			|| (ucc > 127 && PBchar::isLetterOrNumber_helper(ucc));
	}

	static inline bool isDigit(pbuint ucc)
	{
		return (ucc <= '9' && ucc >= '0') || (ucc > 127 && PBchar::category(ucc) == Number_DecimalDigit);
	}

	static inline bool isLower(pbuint ucc)
	{
		return (ucc <= 'z' && ucc >= 'a') || (ucc > 127 && PBchar::category(ucc) == Letter_Lowercase);
	}

	static inline bool isUpper(pbuint ucc)
	{
		return (ucc <= 'Z' && ucc >= 'A') || (ucc > 127 && PBchar::category(ucc) == Letter_Uppercase);
	}

	static inline bool isTitleCase(pbuint ucc)
	{
		return ucc > 127 && PBchar::category(ucc) == Letter_Titlecase;
	}


	inline Category category() const { return PBchar::category(_ucc); }
	inline Direction direction() const { return PBchar::direction(_ucc); }
	inline JoiningType joiningType() const { return PBchar::joiningType(_ucc); }

private:
	static bool isSpace_helper(pbuint ucc);
	static bool isLetter_helper(pbuint ucc);
	static bool isNumber_helper(pbuint ucc);
	static bool isLetterOrNumber_helper(pbuint ucc);


private:
	pbushort _ucc;
};


class PBstring
{
public:
	PBstring(char* s);
	~PBstring();

private:
	PBchar* _s;
};


POLAR_BEAR_END


#endif
