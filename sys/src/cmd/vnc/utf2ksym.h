/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

/*
 * VNC uses X11's keysyms defined in X11/keysym.h, this is a converter
 * from unicode characters to ksyms that other servers use.
 */
static uint32_t
utf2ksym [] = {
	[L'Ą'] =	0x1a1,
	[L'˘'] =	0x1a2,
	[L'Ł'] =	0x1a3,
	[L'Ľ'] =	0x1a5,
	[L'Ś'] =	0x1a6,
	[L'Š'] =	0x1a9,
	[L'Ş'] =	0x1aa,
	[L'Ť'] =	0x1ab,
	[L'Ź'] =	0x1ac,
	[L'Ž'] =	0x1ae,
	[L'Ż'] =	0x1af,
	[L'ą'] =	0x1b1,
	[L'˛'] =	0x1b2,
	[L'ł'] =	0x1b3,
	[L'ľ'] =	0x1b5,
	[L'ś'] =	0x1b6,
	[L'ˇ'] =	0x1b7,
	[L'š'] =	0x1b9,
	[L'ş'] =	0x1ba,
	[L'ť'] =	0x1bb,
	[L'ź'] =	0x1bc,
	[L'˝'] =	0x1bd,
	[L'ž'] =	0x1be,
	[L'ż'] =	0x1bf,
	[L'Ŕ'] =	0x1c0,
	[L'Ă'] =	0x1c3,
	[L'Ĺ'] =	0x1c5,
	[L'Ć'] =	0x1c6,
	[L'Č'] =	0x1c8,
	[L'Ę'] =	0x1ca,
	[L'Ě'] =	0x1cc,
	[L'Ď'] =	0x1cf,
	[L'Đ'] =	0x1d0,
	[L'Ń'] =	0x1d1,
	[L'Ň'] =	0x1d2,
	[L'Ő'] =	0x1d5,
	[L'Ř'] =	0x1d8,
	[L'Ů'] =	0x1d9,
	[L'Ű'] =	0x1db,
	[L'Ţ'] =	0x1de,
	[L'ŕ'] =	0x1e0,
	[L'ă'] =	0x1e3,
	[L'ĺ'] =	0x1e5,
	[L'ć'] =	0x1e6,
	[L'č'] =	0x1e8,
	[L'ę'] =	0x1ea,
	[L'ě'] =	0x1ec,
	[L'ď'] =	0x1ef,
	[L'đ'] =	0x1f0,
	[L'ń'] =	0x1f1,
	[L'ň'] =	0x1f2,
	[L'ő'] =	0x1f5,
	[L'ř'] =	0x1f8,
	[L'ů'] =	0x1f9,
	[L'ű'] =	0x1fb,
	[L'ţ'] =	0x1fe,
	[L'˙'] =	0x1ff,
	[L'Ħ'] =	0x2a1,
	[L'Ĥ'] =	0x2a6,
	[L'İ'] =	0x2a9,
	[L'Ğ'] =	0x2ab,
	[L'Ĵ'] =	0x2ac,
	[L'ħ'] =	0x2b1,
	[L'ĥ'] =	0x2b6,
	[L'ı'] =	0x2b9,
	[L'ğ'] =	0x2bb,
	[L'ĵ'] =	0x2bc,
	[L'Ċ'] =	0x2c5,
	[L'Ĉ'] =	0x2c6,
	[L'Ġ'] =	0x2d5,
	[L'Ĝ'] =	0x2d8,
	[L'Ŭ'] =	0x2dd,
	[L'Ŝ'] =	0x2de,
	[L'ċ'] =	0x2e5,
	[L'ĉ'] =	0x2e6,
	[L'ġ'] =	0x2f5,
	[L'ĝ'] =	0x2f8,
	[L'ŭ'] =	0x2fd,
	[L'ŝ'] =	0x2fe,
	[L'ĸ'] =	0x3a2,
	[L'Ŗ'] =	0x3a3,
	[L'Ĩ'] =	0x3a5,
	[L'Ļ'] =	0x3a6,
	[L'Ē'] =	0x3aa,
	[L'Ģ'] =	0x3ab,
	[L'Ŧ'] =	0x3ac,
	[L'ŗ'] =	0x3b3,
	[L'ĩ'] =	0x3b5,
	[L'ļ'] =	0x3b6,
	[L'ē'] =	0x3ba,
	[L'ģ'] =	0x3bb,
	[L'ŧ'] =	0x3bc,
	[L'Ŋ'] =	0x3bd,
	[L'ŋ'] =	0x3bf,
	[L'Ā'] =	0x3c0,
	[L'Į'] =	0x3c7,
	[L'Ė'] =	0x3cc,
	[L'Ī'] =	0x3cf,
	[L'Ņ'] =	0x3d1,
	[L'Ō'] =	0x3d2,
	[L'Ķ'] =	0x3d3,
	[L'Ų'] =	0x3d9,
	[L'Ũ'] =	0x3dd,
	[L'Ū'] =	0x3de,
	[L'ā'] =	0x3e0,
	[L'į'] =	0x3e7,
	[L'ė'] =	0x3ec,
	[L'ī'] =	0x3ef,
	[L'ņ'] =	0x3f1,
	[L'ō'] =	0x3f2,
	[L'ķ'] =	0x3f3,
	[L'ų'] =	0x3f9,
	[L'ũ'] =	0x3fd,
	[L'ū'] =	0x3fe,
	[L'。'] =	0x4a1,
	[L'〈'] =	0x4a2,
	[L'〉'] =	0x4a3,
	[L'、'] =	0x4a4,
	[L'・'] =	0x4a5,
	[L'ヲ'] =	0x4a6,
	[L'ァ'] =	0x4a7,
	[L'ィ'] =	0x4a8,
	[L'ゥ'] =	0x4a9,
	[L'ェ'] =	0x4aa,
	[L'ォ'] =	0x4ab,
	[L'ャ'] =	0x4ac,
	[L'ュ'] =	0x4ad,
	[L'ョ'] =	0x4ae,
	[L'ッ'] =	0x4af,
	[L'ー'] =	0x4b0,
	[L'ア'] =	0x4b1,
	[L'イ'] =	0x4b2,
	[L'ウ'] =	0x4b3,
	[L'エ'] =	0x4b4,
	[L'オ'] =	0x4b5,
	[L'カ'] =	0x4b6,
	[L'キ'] =	0x4b7,
	[L'ク'] =	0x4b8,
	[L'ケ'] =	0x4b9,
	[L'コ'] =	0x4ba,
	[L'サ'] =	0x4bb,
	[L'シ'] =	0x4bc,
	[L'ス'] =	0x4bd,
	[L'セ'] =	0x4be,
	[L'ソ'] =	0x4bf,
	[L'タ'] =	0x4c0,
	[L'チ'] =	0x4c1,
	[L'ツ'] =	0x4c2,
	[L'テ'] =	0x4c3,
	[L'ト'] =	0x4c4,
	[L'ナ'] =	0x4c5,
	[L'ニ'] =	0x4c6,
	[L'ヌ'] =	0x4c7,
	[L'ネ'] =	0x4c8,
	[L'ノ'] =	0x4c9,
	[L'ハ'] =	0x4ca,
	[L'ヒ'] =	0x4cb,
	[L'フ'] =	0x4cc,
	[L'ヘ'] =	0x4cd,
	[L'ホ'] =	0x4ce,
	[L'マ'] =	0x4cf,
	[L'ミ'] =	0x4d0,
	[L'ム'] =	0x4d1,
	[L'メ'] =	0x4d2,
	[L'モ'] =	0x4d3,
	[L'ヤ'] =	0x4d4,
	[L'ユ'] =	0x4d5,
	[L'ヨ'] =	0x4d6,
	[L'ラ'] =	0x4d7,
	[L'リ'] =	0x4d8,
	[L'ル'] =	0x4d9,
	[L'レ'] =	0x4da,
	[L'ロ'] =	0x4db,
	[L'ワ'] =	0x4dc,
	[L'ン'] =	0x4dd,
	[L'゛'] =	0x4de,
	[L'゜'] =	0x4df,
	[L'۰'] =	0x590,
	[L'۱'] =	0x591,
	[L'۲'] =	0x592,
	[L'۳'] =	0x593,
	[L'۴'] =	0x594,
	[L'۵'] =	0x595,
	[L'۶'] =	0x596,
	[L'۷'] =	0x597,
	[L'۸'] =	0x598,
	[L'۹'] =	0x599,
	[L'٪'] =	0x5a5,
	[L'ٰ'] =	0x5a6,
	[L'ٹ'] =	0x5a7,
	[L'پ'] =	0x5a8,
	[L'چ'] =	0x5a9,
	[L'ڈ'] =	0x5aa,
	[L'ڑ'] =	0x5ab,
	[L'،'] =	0x5ac,
	[L'۔'] =	0x5ae,
	[L'٠'] =	0x5b0,
	[L'١'] =	0x5b1,
	[L'٢'] =	0x5b2,
	[L'٣'] =	0x5b3,
	[L'٤'] =	0x5b4,
	[L'٥'] =	0x5b5,
	[L'٦'] =	0x5b6,
	[L'٧'] =	0x5b7,
	[L'٨'] =	0x5b8,
	[L'٩'] =	0x5b9,
	[L'؛'] =	0x5bb,
	[L'؟'] =	0x5bf,
	[L'ء'] =	0x5c1,
	[L'آ'] =	0x5c2,
	[L'أ'] =	0x5c3,
	[L'ؤ'] =	0x5c4,
	[L'إ'] =	0x5c5,
	[L'ئ'] =	0x5c6,
	[L'ا'] =	0x5c7,
	[L'ب'] =	0x5c8,
	[L'ة'] =	0x5c9,
	[L'ت'] =	0x5ca,
	[L'ث'] =	0x5cb,
	[L'ج'] =	0x5cc,
	[L'ح'] =	0x5cd,
	[L'خ'] =	0x5ce,
	[L'د'] =	0x5cf,
	[L'ذ'] =	0x5d0,
	[L'ر'] =	0x5d1,
	[L'ز'] =	0x5d2,
	[L'س'] =	0x5d3,
	[L'ش'] =	0x5d4,
	[L'ص'] =	0x5d5,
	[L'ض'] =	0x5d6,
	[L'ط'] =	0x5d7,
	[L'ظ'] =	0x5d8,
	[L'ع'] =	0x5d9,
	[L'غ'] =	0x5da,
	[L'ـ'] =	0x5e0,
	[L'ف'] =	0x5e1,
	[L'ق'] =	0x5e2,
	[L'ك'] =	0x5e3,
	[L'ل'] =	0x5e4,
	[L'م'] =	0x5e5,
	[L'ن'] =	0x5e6,
	[L'ه'] =	0x5e7,
	[L'و'] =	0x5e8,
	[L'ى'] =	0x5e9,
	[L'ي'] =	0x5ea,
	[L'ً'] =	0x5eb,
	[L'ٌ'] =	0x5ec,
	[L'ٍ'] =	0x5ed,
	[L'َ'] =	0x5ee,
	[L'ُ'] =	0x5ef,
	[L'ِ'] =	0x5f0,
	[L'ّ'] =	0x5f1,
	[L'ْ'] =	0x5f2,
	[L'ٓ'] =	0x5f3,
	[L'ٔ'] =	0x5f4,
	[L'ٕ'] =	0x5f5,
	[L'ژ'] =	0x5f6,
	[L'ڤ'] =	0x5f7,
	[L'ک'] =	0x5f8,
	[L'گ'] =	0x5f9,
	[L'ں'] =	0x5fa,
	[L'ھ'] =	0x5fb,
	[L'ی'] =	0x5fc,
	[L'ے'] =	0x5fd,
	[L'ہ'] =	0x5fe,
	[L'Ғ'] =	0x680,
	[L'Җ'] =	0x681,
	[L'Қ'] =	0x682,
	[L'Ҝ'] =	0x683,
	[L'Ң'] =	0x684,
	[L'Ү'] =	0x685,
	[L'Ұ'] =	0x686,
	[L'Ҳ'] =	0x687,
	[L'Ҷ'] =	0x688,
	[L'Ҹ'] =	0x689,
	[L'Һ'] =	0x68a,
	[L'Ә'] =	0x68c,
	[L'Ӣ'] =	0x68d,
	[L'Ө'] =	0x68e,
	[L'Ӯ'] =	0x68f,
	[L'ғ'] =	0x690,
	[L'җ'] =	0x691,
	[L'қ'] =	0x692,
	[L'ҝ'] =	0x693,
	[L'ң'] =	0x694,
	[L'ү'] =	0x695,
	[L'ұ'] =	0x696,
	[L'ҳ'] =	0x697,
	[L'ҷ'] =	0x698,
	[L'ҹ'] =	0x699,
	[L'һ'] =	0x69a,
	[L'ә'] =	0x69c,
	[L'ӣ'] =	0x69d,
	[L'ө'] =	0x69e,
	[L'ӯ'] =	0x69f,
	[L'ђ'] =	0x6a1,
	[L'ѓ'] =	0x6a2,
	[L'ё'] =	0x6a3,
	[L'є'] =	0x6a4,
	[L'ѕ'] =	0x6a5,
	[L'і'] =	0x6a6,
	[L'ї'] =	0x6a7,
	[L'ј'] =	0x6a8,
	[L'љ'] =	0x6a9,
	[L'њ'] =	0x6aa,
	[L'ћ'] =	0x6ab,
	[L'ќ'] =	0x6ac,
	[L'ґ'] =	0x6ad,
	[L'ў'] =	0x6ae,
	[L'џ'] =	0x6af,
	[L'№'] =	0x6b0,
	[L'Ђ'] =	0x6b1,
	[L'Ѓ'] =	0x6b2,
	[L'Ё'] =	0x6b3,
	[L'Є'] =	0x6b4,
	[L'Ѕ'] =	0x6b5,
	[L'І'] =	0x6b6,
	[L'Ї'] =	0x6b7,
	[L'Ј'] =	0x6b8,
	[L'Љ'] =	0x6b9,
	[L'Њ'] =	0x6ba,
	[L'Ћ'] =	0x6bb,
	[L'Ќ'] =	0x6bc,
	[L'Ґ'] =	0x6bd,
	[L'Ў'] =	0x6be,
	[L'Џ'] =	0x6bf,
	[L'ю'] =	0x6c0,
	[L'а'] =	0x6c1,
	[L'б'] =	0x6c2,
	[L'ц'] =	0x6c3,
	[L'д'] =	0x6c4,
	[L'е'] =	0x6c5,
	[L'ф'] =	0x6c6,
	[L'г'] =	0x6c7,
	[L'х'] =	0x6c8,
	[L'и'] =	0x6c9,
	[L'й'] =	0x6ca,
	[L'к'] =	0x6cb,
	[L'л'] =	0x6cc,
	[L'м'] =	0x6cd,
	[L'н'] =	0x6ce,
	[L'о'] =	0x6cf,
	[L'п'] =	0x6d0,
	[L'я'] =	0x6d1,
	[L'р'] =	0x6d2,
	[L'с'] =	0x6d3,
	[L'т'] =	0x6d4,
	[L'у'] =	0x6d5,
	[L'ж'] =	0x6d6,
	[L'в'] =	0x6d7,
	[L'ь'] =	0x6d8,
	[L'ы'] =	0x6d9,
	[L'з'] =	0x6da,
	[L'ш'] =	0x6db,
	[L'э'] =	0x6dc,
	[L'щ'] =	0x6dd,
	[L'ч'] =	0x6de,
	[L'ъ'] =	0x6df,
	[L'Ю'] =	0x6e0,
	[L'А'] =	0x6e1,
	[L'Б'] =	0x6e2,
	[L'Ц'] =	0x6e3,
	[L'Д'] =	0x6e4,
	[L'Е'] =	0x6e5,
	[L'Ф'] =	0x6e6,
	[L'Г'] =	0x6e7,
	[L'Х'] =	0x6e8,
	[L'И'] =	0x6e9,
	[L'Й'] =	0x6ea,
	[L'К'] =	0x6eb,
	[L'Л'] =	0x6ec,
	[L'М'] =	0x6ed,
	[L'Н'] =	0x6ee,
	[L'О'] =	0x6ef,
	[L'П'] =	0x6f0,
	[L'Я'] =	0x6f1,
	[L'Р'] =	0x6f2,
	[L'С'] =	0x6f3,
	[L'Т'] =	0x6f4,
	[L'У'] =	0x6f5,
	[L'Ж'] =	0x6f6,
	[L'В'] =	0x6f7,
	[L'Ь'] =	0x6f8,
	[L'Ы'] =	0x6f9,
	[L'З'] =	0x6fa,
	[L'Ш'] =	0x6fb,
	[L'Э'] =	0x6fc,
	[L'Щ'] =	0x6fd,
	[L'Ч'] =	0x6fe,
	[L'Ъ'] =	0x6ff,
	[L'Ά'] =	0x7a1,
	[L'Έ'] =	0x7a2,
	[L'Ή'] =	0x7a3,
	[L'Ί'] =	0x7a4,
	[L'Ϊ'] =	0x7a5,
	[L'Ό'] =	0x7a7,
	[L'Ύ'] =	0x7a8,
	[L'Ϋ'] =	0x7a9,
	[L'Ώ'] =	0x7ab,
	[L'΅'] =	0x7ae,
	[L'―'] =	0x7af,
	[L'ά'] =	0x7b1,
	[L'έ'] =	0x7b2,
	[L'ή'] =	0x7b3,
	[L'ί'] =	0x7b4,
	[L'ϊ'] =	0x7b5,
	[L'ΐ'] =	0x7b6,
	[L'ό'] =	0x7b7,
	[L'ύ'] =	0x7b8,
	[L'ϋ'] =	0x7b9,
	[L'ΰ'] =	0x7ba,
	[L'ώ'] =	0x7bb,
	[L'Α'] =	0x7c1,
	[L'Β'] =	0x7c2,
	[L'Γ'] =	0x7c3,
	[L'Δ'] =	0x7c4,
	[L'Ε'] =	0x7c5,
	[L'Ζ'] =	0x7c6,
	[L'Η'] =	0x7c7,
	[L'Θ'] =	0x7c8,
	[L'Ι'] =	0x7c9,
	[L'Κ'] =	0x7ca,
	[L'Λ'] =	0x7cb,
	[L'Μ'] =	0x7cc,
	[L'Ν'] =	0x7cd,
	[L'Ξ'] =	0x7ce,
	[L'Ο'] =	0x7cf,
	[L'Π'] =	0x7d0,
	[L'Ρ'] =	0x7d1,
	[L'Σ'] =	0x7d2,
	[L'Τ'] =	0x7d4,
	[L'Υ'] =	0x7d5,
	[L'Φ'] =	0x7d6,
	[L'Χ'] =	0x7d7,
	[L'Ψ'] =	0x7d8,
	[L'Ω'] =	0x7d9,
	[L'α'] =	0x7e1,
	[L'β'] =	0x7e2,
	[L'γ'] =	0x7e3,
	[L'δ'] =	0x7e4,
	[L'ε'] =	0x7e5,
	[L'ζ'] =	0x7e6,
	[L'η'] =	0x7e7,
	[L'θ'] =	0x7e8,
	[L'ι'] =	0x7e9,
	[L'κ'] =	0x7ea,
	[L'λ'] =	0x7eb,
	[L'μ'] =	0x7ec,
	[L'ν'] =	0x7ed,
	[L'ξ'] =	0x7ee,
	[L'ο'] =	0x7ef,
	[L'π'] =	0x7f0,
	[L'ρ'] =	0x7f1,
	[L'σ'] =	0x7f2,
	[L'ς'] =	0x7f3,
	[L'τ'] =	0x7f4,
	[L'υ'] =	0x7f5,
	[L'φ'] =	0x7f6,
	[L'χ'] =	0x7f7,
	[L'ψ'] =	0x7f8,
	[L'ω'] =	0x7f9,
	[L'⌠'] =	0x8a4,
	[L'⌡'] =	0x8a5,
	[L'⌜'] =	0x8a7,
	[L'⌝'] =	0x8a8,
	[L'⌞'] =	0x8a9,
	[L'⌟'] =	0x8aa,
	[L'≤'] =	0x8bc,
	[L'≠'] =	0x8bd,
	[L'≥'] =	0x8be,
	[L'∫'] =	0x8bf,
	[L'∴'] =	0x8c0,
	[L'∞'] =	0x8c2,
	[L'∇'] =	0x8c5,
	[L'≅'] =	0x8c8,
	[L'≆'] =	0x8c9,
	[L'⊢'] =	0x8ce,
	[L'√'] =	0x8d6,
	[L'⊂'] =	0x8da,
	[L'⊃'] =	0x8db,
	[L'∩'] =	0x8dc,
	[L'∪'] =	0x8dd,
	[L'∧'] =	0x8de,
	[L'∨'] =	0x8df,
	[L'ƒ'] =	0x8f6,
	[L'←'] =	0x8fb,
	[L'↑'] =	0x8fc,
	[L'→'] =	0x8fd,
	[L'↓'] =	0x8fe,
	[L'␢'] =	0x9df,
	[L'♦'] =	0x9e0,
	[L'▦'] =	0x9e1,
	[L'␉'] =	0x9e2,
	[L'␌'] =	0x9e3,
	[L'␍'] =	0x9e4,
	[L'␊'] =	0x9e5,
	[L'␋'] =	0x9e9,
	[L'┘'] =	0x9ea,
	[L'┐'] =	0x9eb,
	[L'┌'] =	0x9ec,
	[L'└'] =	0x9ed,
	[L'┼'] =	0x9ee,
	[L'─'] =	0x9ef,
	[L'├'] =	0x9f4,
	[L'┤'] =	0x9f5,
	[L'┴'] =	0x9f6,
	[L'┬'] =	0x9f7,
	[L'│'] =	0x9f8,
	[L' '] =	0xaa1,
	[L' '] =	0xaa2,
	[L' '] =	0xaa3,
	[L' '] =	0xaa4,
	[L' '] =	0xaa5,
	[L' '] =	0xaa6,
	[L' '] =	0xaa7,
	[L' '] =	0xaa8,
	[L'—'] =	0xaa9,
	[L'–'] =	0xaaa,
	[L'…'] =	0xaae,
	[L'‥'] =	0xaaf,
	[L'⅓'] =	0xab0,
	[L'⅔'] =	0xab1,
	[L'⅕'] =	0xab2,
	[L'⅖'] =	0xab3,
	[L'⅗'] =	0xab4,
	[L'⅘'] =	0xab5,
	[L'⅙'] =	0xab6,
	[L'⅚'] =	0xab7,
	[L'℅'] =	0xab8,
	[L'‒'] =	0xabb,
	[L'‹'] =	0xabc,
	[L'․'] =	0xabd,
	[L'›'] =	0xabe,
	[L'⅛'] =	0xac3,
	[L'⅜'] =	0xac4,
	[L'⅝'] =	0xac5,
	[L'⅞'] =	0xac6,
	[L'™'] =	0xac9,
	[L'℠'] =	0xaca,
	[L'◁'] =	0xacc,
	[L'▷'] =	0xacd,
	[L'○'] =	0xace,
	[L'▭'] =	0xacf,
	[L'‘'] =	0xad0,
	[L'’'] =	0xad1,
	[L'“'] =	0xad2,
	[L'”'] =	0xad3,
	[L'℞'] =	0xad4,
	[L'′'] =	0xad6,
	[L'″'] =	0xad7,
	[L'✝'] =	0xad9,
	[L'∎'] =	0xadb,
	[L'◂'] =	0xadc,
	[L'‣'] =	0xadd,
	[L'●'] =	0xade,
	[L'▬'] =	0xadf,
	[L'◦'] =	0xae0,
	[L'▫'] =	0xae1,
	[L'▮'] =	0xae2,
	[L'▵'] =	0xae3,
	[L'▿'] =	0xae4,
	[L'☆'] =	0xae5,
	[L'•'] =	0xae6,
	[L'▪'] =	0xae7,
	[L'▴'] =	0xae8,
	[L'▾'] =	0xae9,
	[L'☚'] =	0xaea,
	[L'☛'] =	0xaeb,
	[L'♣'] =	0xaec,
	[L'♥'] =	0xaee,
	[L'✠'] =	0xaf0,
	[L'†'] =	0xaf1,
	[L'‡'] =	0xaf2,
	[L'✓'] =	0xaf3,
	[L'☒'] =	0xaf4,
	[L'♯'] =	0xaf5,
	[L'♭'] =	0xaf6,
	[L'♂'] =	0xaf7,
	[L'♀'] =	0xaf8,
	[L'℡'] =	0xaf9,
	[L'⌕'] =	0xafa,
	[L'℗'] =	0xafb,
	[L'‸'] =	0xafc,
	[L'‚'] =	0xafd,
	[L'„'] =	0xafe,
	[L'‗'] =	0xcdf,
	[L'א'] =	0xce0,
	[L'ב'] =	0xce1,
	[L'ג'] =	0xce2,
	[L'ד'] =	0xce3,
	[L'ה'] =	0xce4,
	[L'ו'] =	0xce5,
	[L'ז'] =	0xce6,
	[L'ח'] =	0xce7,
	[L'ט'] =	0xce8,
	[L'י'] =	0xce9,
	[L'ך'] =	0xcea,
	[L'כ'] =	0xceb,
	[L'ל'] =	0xcec,
	[L'ם'] =	0xced,
	[L'מ'] =	0xcee,
	[L'ן'] =	0xcef,
	[L'נ'] =	0xcf0,
	[L'ס'] =	0xcf1,
	[L'ע'] =	0xcf2,
	[L'ף'] =	0xcf3,
	[L'פ'] =	0xcf4,
	[L'ץ'] =	0xcf5,
	[L'צ'] =	0xcf6,
	[L'ק'] =	0xcf7,
	[L'ר'] =	0xcf8,
	[L'ש'] =	0xcf9,
	[L'ת'] =	0xcfa,
	[L'ก'] =	0xda1,
	[L'ข'] =	0xda2,
	[L'ฃ'] =	0xda3,
	[L'ค'] =	0xda4,
	[L'ฅ'] =	0xda5,
	[L'ฆ'] =	0xda6,
	[L'ง'] =	0xda7,
	[L'จ'] =	0xda8,
	[L'ฉ'] =	0xda9,
	[L'ช'] =	0xdaa,
	[L'ซ'] =	0xdab,
	[L'ฌ'] =	0xdac,
	[L'ญ'] =	0xdad,
	[L'ฎ'] =	0xdae,
	[L'ฏ'] =	0xdaf,
	[L'ฐ'] =	0xdb0,
	[L'ฑ'] =	0xdb1,
	[L'ฒ'] =	0xdb2,
	[L'ณ'] =	0xdb3,
	[L'ด'] =	0xdb4,
	[L'ต'] =	0xdb5,
	[L'ถ'] =	0xdb6,
	[L'ท'] =	0xdb7,
	[L'ธ'] =	0xdb8,
	[L'น'] =	0xdb9,
	[L'บ'] =	0xdba,
	[L'ป'] =	0xdbb,
	[L'ผ'] =	0xdbc,
	[L'ฝ'] =	0xdbd,
	[L'พ'] =	0xdbe,
	[L'ฟ'] =	0xdbf,
	[L'ภ'] =	0xdc0,
	[L'ม'] =	0xdc1,
	[L'ย'] =	0xdc2,
	[L'ร'] =	0xdc3,
	[L'ฤ'] =	0xdc4,
	[L'ล'] =	0xdc5,
	[L'ฦ'] =	0xdc6,
	[L'ว'] =	0xdc7,
	[L'ศ'] =	0xdc8,
	[L'ษ'] =	0xdc9,
	[L'ส'] =	0xdca,
	[L'ห'] =	0xdcb,
	[L'ฬ'] =	0xdcc,
	[L'อ'] =	0xdcd,
	[L'ฮ'] =	0xdce,
	[L'ฯ'] =	0xdcf,
	[L'ะ'] =	0xdd0,
	[L'ั'] =	0xdd1,
	[L'า'] =	0xdd2,
	[L'ำ'] =	0xdd3,
	[L'ิ'] =	0xdd4,
	[L'ี'] =	0xdd5,
	[L'ึ'] =	0xdd6,
	[L'ื'] =	0xdd7,
	[L'ุ'] =	0xdd8,
	[L'ู'] =	0xdd9,
	[L'ฺ'] =	0xdda,
	[L'฾'] =	0xdde,
	[L'฿'] =	0xddf,
	[L'เ'] =	0xde0,
	[L'แ'] =	0xde1,
	[L'โ'] =	0xde2,
	[L'ใ'] =	0xde3,
	[L'ไ'] =	0xde4,
	[L'ๅ'] =	0xde5,
	[L'ๆ'] =	0xde6,
	[L'็'] =	0xde7,
	[L'่'] =	0xde8,
	[L'้'] =	0xde9,
	[L'๊'] =	0xdea,
	[L'๋'] =	0xdeb,
	[L'์'] =	0xdec,
	[L'ํ'] =	0xded,
	[L'๐'] =	0xdf0,
	[L'๑'] =	0xdf1,
	[L'๒'] =	0xdf2,
	[L'๓'] =	0xdf3,
	[L'๔'] =	0xdf4,
	[L'๕'] =	0xdf5,
	[L'๖'] =	0xdf6,
	[L'๗'] =	0xdf7,
	[L'๘'] =	0xdf8,
	[L'๙'] =	0xdf9,
	[L'ᄁ'] =	0xea2,
	[L'ᄂ'] =	0xea4,
	[L'ᄃ'] =	0xea7,
	[L'ᄄ'] =	0xea8,
	[L'ᄅ'] =	0xea9,
	[L'ᄆ'] =	0xeb1,
	[L'ᄇ'] =	0xeb2,
	[L'ᄈ'] =	0xeb3,
	[L'ᄉ'] =	0xeb5,
	[L'ᄊ'] =	0xeb6,
	[L'ᄋ'] =	0xeb7,
	[L'ᄌ'] =	0xeb8,
	[L'ᄍ'] =	0xeb9,
	[L'ᄎ'] =	0xeba,
	[L'ᄏ'] =	0xebb,
	[L'ᄐ'] =	0xebc,
	[L'ᄑ'] =	0xebd,
	[L'ᄒ'] =	0xebe,
	[L'ᅡ'] =	0xebf,
	[L'ᅢ'] =	0xec0,
	[L'ᅣ'] =	0xec1,
	[L'ᅤ'] =	0xec2,
	[L'ᅥ'] =	0xec3,
	[L'ᅦ'] =	0xec4,
	[L'ᅧ'] =	0xec5,
	[L'ᅨ'] =	0xec6,
	[L'ᅩ'] =	0xec7,
	[L'ᅪ'] =	0xec8,
	[L'ᅫ'] =	0xec9,
	[L'ᅬ'] =	0xeca,
	[L'ᅭ'] =	0xecb,
	[L'ᅮ'] =	0xecc,
	[L'ᅯ'] =	0xecd,
	[L'ᅰ'] =	0xece,
	[L'ᅱ'] =	0xecf,
	[L'ᅲ'] =	0xed0,
	[L'ᅳ'] =	0xed1,
	[L'ᅴ'] =	0xed2,
	[L'ᅵ'] =	0xed3,
	[L'ᆨ'] =	0xed4,
	[L'ᆩ'] =	0xed5,
	[L'ᆪ'] =	0xed6,
	[L'ᆫ'] =	0xed7,
	[L'ᆬ'] =	0xed8,
	[L'ᆭ'] =	0xed9,
	[L'ᆮ'] =	0xeda,
	[L'ᆯ'] =	0xedb,
	[L'ᆰ'] =	0xedc,
	[L'ᆱ'] =	0xedd,
	[L'ᆲ'] =	0xede,
	[L'ᆳ'] =	0xedf,
	[L'ᆴ'] =	0xee0,
	[L'ᆵ'] =	0xee1,
	[L'ᆶ'] =	0xee2,
	[L'ᆷ'] =	0xee3,
	[L'ᆸ'] =	0xee4,
	[L'ᆹ'] =	0xee5,
	[L'ᆺ'] =	0xee6,
	[L'ᆻ'] =	0xee7,
	[L'ᆼ'] =	0xee8,
	[L'ᆽ'] =	0xee9,
	[L'ᆾ'] =	0xeea,
	[L'ᆿ'] =	0xeeb,
	[L'ᇀ'] =	0xeec,
	[L'ᇁ'] =	0xeed,
	[L'ᇂ'] =	0xeee,
	[L'ᅀ'] =	0xef2,
	[L'ᅙ'] =	0xef5,
	[L'ᆞ'] =	0xef6,
	[L'ᇫ'] =	0xef8,
	[L'ᇹ'] =	0xefa,
	[L'₩'] =	0xeff,
	[L'Ḃ'] =	0x12a1,
	[L'ḃ'] =	0x12a2,
	[L'Ḋ'] =	0x12a6,
	[L'Ẁ'] =	0x12a8,
	[L'Ẃ'] =	0x12aa,
	[L'ḋ'] =	0x12ab,
	[L'Ỳ'] =	0x12ac,
	[L'Ḟ'] =	0x12b0,
	[L'ḟ'] =	0x12b1,
	[L'Ṁ'] =	0x12b4,
	[L'ṁ'] =	0x12b5,
	[L'Ṗ'] =	0x12b7,
	[L'ẁ'] =	0x12b8,
	[L'ṗ'] =	0x12b9,
	[L'ẃ'] =	0x12ba,
	[L'Ṡ'] =	0x12bb,
	[L'ỳ'] =	0x12bc,
	[L'Ẅ'] =	0x12bd,
	[L'ẅ'] =	0x12be,
	[L'ṡ'] =	0x12bf,
	[L'Ŵ'] =	0x12d0,
	[L'Ṫ'] =	0x12d7,
	[L'Ŷ'] =	0x12de,
	[L'ŵ'] =	0x12f0,
	[L'ṫ'] =	0x12f7,
	[L'ŷ'] =	0x12fe,
	[L'Œ'] =	0x13bc,
	[L'œ'] =	0x13bd,
	[L'Ÿ'] =	0x13be,
	[L'❁'] =	0x14a1,
	[L'§'] =	0x14a2,
	[L'։'] =	0x14a3,
	[L')'] =	0x14a4,
	[L'('] =	0x14a5,
	[L'»'] =	0x14a6,
	[L'«'] =	0x14a7,
	[L'.'] =	0x14a9,
	[L'՝'] =	0x14aa,
	[L','] =	0x14ab,
	[L'֊'] =	0x14ad,
	[L'՜'] =	0x14af,
	[L'՛'] =	0x14b0,
	[L'՞'] =	0x14b1,
	[L'Ա'] =	0x14b2,
	[L'ա'] =	0x14b3,
	[L'Բ'] =	0x14b4,
	[L'բ'] =	0x14b5,
	[L'Գ'] =	0x14b6,
	[L'գ'] =	0x14b7,
	[L'Դ'] =	0x14b8,
	[L'դ'] =	0x14b9,
	[L'Ե'] =	0x14ba,
	[L'ե'] =	0x14bb,
	[L'Զ'] =	0x14bc,
	[L'զ'] =	0x14bd,
	[L'Է'] =	0x14be,
	[L'է'] =	0x14bf,
	[L'Ը'] =	0x14c0,
	[L'ը'] =	0x14c1,
	[L'Թ'] =	0x14c2,
	[L'թ'] =	0x14c3,
	[L'Ժ'] =	0x14c4,
	[L'ժ'] =	0x14c5,
	[L'Ի'] =	0x14c6,
	[L'ի'] =	0x14c7,
	[L'Լ'] =	0x14c8,
	[L'լ'] =	0x14c9,
	[L'Խ'] =	0x14ca,
	[L'խ'] =	0x14cb,
	[L'Ծ'] =	0x14cc,
	[L'ծ'] =	0x14cd,
	[L'Կ'] =	0x14ce,
	[L'կ'] =	0x14cf,
	[L'Հ'] =	0x14d0,
	[L'հ'] =	0x14d1,
	[L'Ձ'] =	0x14d2,
	[L'ձ'] =	0x14d3,
	[L'Ղ'] =	0x14d4,
	[L'ղ'] =	0x14d5,
	[L'Ճ'] =	0x14d6,
	[L'ճ'] =	0x14d7,
	[L'Մ'] =	0x14d8,
	[L'մ'] =	0x14d9,
	[L'Յ'] =	0x14da,
	[L'յ'] =	0x14db,
	[L'Ն'] =	0x14dc,
	[L'ն'] =	0x14dd,
	[L'Շ'] =	0x14de,
	[L'շ'] =	0x14df,
	[L'Ո'] =	0x14e0,
	[L'ո'] =	0x14e1,
	[L'Չ'] =	0x14e2,
	[L'չ'] =	0x14e3,
	[L'Պ'] =	0x14e4,
	[L'պ'] =	0x14e5,
	[L'Ջ'] =	0x14e6,
	[L'ջ'] =	0x14e7,
	[L'Ռ'] =	0x14e8,
	[L'ռ'] =	0x14e9,
	[L'Ս'] =	0x14ea,
	[L'ս'] =	0x14eb,
	[L'Վ'] =	0x14ec,
	[L'վ'] =	0x14ed,
	[L'Տ'] =	0x14ee,
	[L'տ'] =	0x14ef,
	[L'Ր'] =	0x14f0,
	[L'ր'] =	0x14f1,
	[L'Ց'] =	0x14f2,
	[L'ց'] =	0x14f3,
	[L'Ւ'] =	0x14f4,
	[L'ւ'] =	0x14f5,
	[L'Փ'] =	0x14f6,
	[L'փ'] =	0x14f7,
	[L'Ք'] =	0x14f8,
	[L'ք'] =	0x14f9,
	[L'Օ'] =	0x14fa,
	[L'օ'] =	0x14fb,
	[L'Ֆ'] =	0x14fc,
	[L'ֆ'] =	0x14fd,
	[L'\''] =	0x14ff,
	[L'ა'] =	0x15d0,
	[L'ბ'] =	0x15d1,
	[L'გ'] =	0x15d2,
	[L'დ'] =	0x15d3,
	[L'ე'] =	0x15d4,
	[L'ვ'] =	0x15d5,
	[L'ზ'] =	0x15d6,
	[L'თ'] =	0x15d7,
	[L'ი'] =	0x15d8,
	[L'კ'] =	0x15d9,
	[L'ლ'] =	0x15da,
	[L'მ'] =	0x15db,
	[L'ნ'] =	0x15dc,
	[L'ო'] =	0x15dd,
	[L'პ'] =	0x15de,
	[L'ჟ'] =	0x15df,
	[L'რ'] =	0x15e0,
	[L'ს'] =	0x15e1,
	[L'ტ'] =	0x15e2,
	[L'უ'] =	0x15e3,
	[L'ფ'] =	0x15e4,
	[L'ქ'] =	0x15e5,
	[L'ღ'] =	0x15e6,
	[L'ყ'] =	0x15e7,
	[L'შ'] =	0x15e8,
	[L'ჩ'] =	0x15e9,
	[L'ც'] =	0x15ea,
	[L'ძ'] =	0x15eb,
	[L'წ'] =	0x15ec,
	[L'ჭ'] =	0x15ed,
	[L'ხ'] =	0x15ee,
	[L'ჯ'] =	0x15ef,
	[L'ჰ'] =	0x15f0,
	[L'ჱ'] =	0x15f1,
	[L'ჲ'] =	0x15f2,
	[L'ჳ'] =	0x15f3,
	[L'ჴ'] =	0x15f4,
	[L'ჵ'] =	0x15f5,
	[L'ჶ'] =	0x15f6,
	[L''] =	0x16a2,
	[L'Ẋ'] =	0x16a3,
	[L''] =	0x16a5,
	[L'Ĭ'] =	0x16a6,
	[L''] =	0x16a7,
	[L''] =	0x16a8,
	[L'Ƶ'] =	0x16a9,
	[L'Ǧ'] =	0x16aa,
	[L'Ɵ'] =	0x16af,
	[L''] =	0x16b2,
	[L'ẋ'] =	0x16b3,
	[L'Ǒ'] =	0x16b4,
	[L''] =	0x16b5,
	[L'ĭ'] =	0x16b6,
	[L''] =	0x16b7,
	[L''] =	0x16b8,
	[L'ƶ'] =	0x16b9,
	[L'ǧ'] =	0x16ba,
	[L'ǒ'] =	0x16bd,
	[L'ɵ'] =	0x16bf,
	[L'Ə'] =	0x16c6,
	[L'Ḷ'] =	0x16d1,
	[L''] =	0x16d2,
	[L''] =	0x16d3,
	[L'ḷ'] =	0x16e1,
	[L''] =	0x16e2,
	[L''] =	0x16e3,
	[L'ə'] =	0x16f6,
	[L'̃'] =	0x1e9f,
	[L'Ạ'] =	0x1ea0,
	[L'ạ'] =	0x1ea1,
	[L'Ả'] =	0x1ea2,
	[L'ả'] =	0x1ea3,
	[L'Ấ'] =	0x1ea4,
	[L'ấ'] =	0x1ea5,
	[L'Ầ'] =	0x1ea6,
	[L'ầ'] =	0x1ea7,
	[L'Ẩ'] =	0x1ea8,
	[L'ẩ'] =	0x1ea9,
	[L'Ẫ'] =	0x1eaa,
	[L'ẫ'] =	0x1eab,
	[L'Ậ'] =	0x1eac,
	[L'ậ'] =	0x1ead,
	[L'Ắ'] =	0x1eae,
	[L'ắ'] =	0x1eaf,
	[L'Ằ'] =	0x1eb0,
	[L'ằ'] =	0x1eb1,
	[L'Ẳ'] =	0x1eb2,
	[L'ẳ'] =	0x1eb3,
	[L'Ẵ'] =	0x1eb4,
	[L'ẵ'] =	0x1eb5,
	[L'Ặ'] =	0x1eb6,
	[L'ặ'] =	0x1eb7,
	[L'Ẹ'] =	0x1eb8,
	[L'ẹ'] =	0x1eb9,
	[L'Ẻ'] =	0x1eba,
	[L'ẻ'] =	0x1ebb,
	[L'Ẽ'] =	0x1ebc,
	[L'ẽ'] =	0x1ebd,
	[L'Ế'] =	0x1ebe,
	[L'ế'] =	0x1ebf,
	[L'Ề'] =	0x1ec0,
	[L'ề'] =	0x1ec1,
	[L'Ể'] =	0x1ec2,
	[L'ể'] =	0x1ec3,
	[L'Ễ'] =	0x1ec4,
	[L'ễ'] =	0x1ec5,
	[L'Ệ'] =	0x1ec6,
	[L'ệ'] =	0x1ec7,
	[L'Ỉ'] =	0x1ec8,
	[L'ỉ'] =	0x1ec9,
	[L'Ị'] =	0x1eca,
	[L'ị'] =	0x1ecb,
	[L'Ọ'] =	0x1ecc,
	[L'ọ'] =	0x1ecd,
	[L'Ỏ'] =	0x1ece,
	[L'ỏ'] =	0x1ecf,
	[L'Ố'] =	0x1ed0,
	[L'ố'] =	0x1ed1,
	[L'Ồ'] =	0x1ed2,
	[L'ồ'] =	0x1ed3,
	[L'Ổ'] =	0x1ed4,
	[L'ổ'] =	0x1ed5,
	[L'Ỗ'] =	0x1ed6,
	[L'ỗ'] =	0x1ed7,
	[L'Ộ'] =	0x1ed8,
	[L'ộ'] =	0x1ed9,
	[L'Ớ'] =	0x1eda,
	[L'ớ'] =	0x1edb,
	[L'Ờ'] =	0x1edc,
	[L'ờ'] =	0x1edd,
	[L'Ở'] =	0x1ede,
	[L'ở'] =	0x1edf,
	[L'Ỡ'] =	0x1ee0,
	[L'ỡ'] =	0x1ee1,
	[L'Ợ'] =	0x1ee2,
	[L'ợ'] =	0x1ee3,
	[L'Ụ'] =	0x1ee4,
	[L'ụ'] =	0x1ee5,
	[L'Ủ'] =	0x1ee6,
	[L'ủ'] =	0x1ee7,
	[L'Ứ'] =	0x1ee8,
	[L'ứ'] =	0x1ee9,
	[L'Ừ'] =	0x1eea,
	[L'ừ'] =	0x1eeb,
	[L'Ử'] =	0x1eec,
	[L'ử'] =	0x1eed,
	[L'Ữ'] =	0x1eee,
	[L'ữ'] =	0x1eef,
	[L'Ự'] =	0x1ef0,
	[L'ự'] =	0x1ef1,
	[L'̀'] =	0x1ef2,
	[L'́'] =	0x1ef3,
	[L'Ỵ'] =	0x1ef4,
	[L'ỵ'] =	0x1ef5,
	[L'Ỷ'] =	0x1ef6,
	[L'ỷ'] =	0x1ef7,
	[L'Ỹ'] =	0x1ef8,
	[L'ỹ'] =	0x1ef9,
	[L'Ơ'] =	0x1efa,
	[L'ơ'] =	0x1efb,
	[L'Ư'] =	0x1efc,
	[L'ư'] =	0x1efd,
	[L'̉'] =	0x1efe,
	[L'̣'] =	0x1eff,
	[L'₠'] =	0x20a0,
	[L'₡'] =	0x20a1,
	[L'₢'] =	0x20a2,
	[L'₣'] =	0x20a3,
	[L'₤'] =	0x20a4,
	[L'₥'] =	0x20a5,
	[L'₦'] =	0x20a6,
	[L'₧'] =	0x20a7,
	[L'₨'] =	0x20a8,
	[L'₪'] =	0x20aa,
	[L'₫'] =	0x20ab,
	[L'€'] =	0x20ac,

};
