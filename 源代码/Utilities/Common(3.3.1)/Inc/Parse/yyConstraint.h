#ifndef FDO_CONSTRAINT_YYERRCODE
#define FDO_CONSTRAINT_YYERRCODE 256
#endif

#define FdoToken_NULL 257
#define FdoToken_TRUE 258
#define FdoToken_FALSE 259
#define FdoToken_DATE 260
#define FdoToken_TIME 261
#define FdoToken_TIMESTAMP 262
#define FdoToken_GEOMFROMTEXT 263
#define FdoToken_AND 264
#define FdoToken_OR 265
#define FdoToken_NOT 266
#define FdoToken_LIKE 267
#define FdoToken_IN 268
#define FdoToken_BEYOND 269
#define FdoToken_WITHINDISTANCE 270
#define FdoToken_CONTAINS 271
#define FdoToken_COVEREDBY 272
#define FdoToken_CROSSES 273
#define FdoToken_DISJOINT 274
#define FdoToken_ENVELOPEINTERSECTS 275
#define FdoToken_EQUALS 276
#define FdoToken_INTERSECTS 277
#define FdoToken_INSIDE 278
#define FdoToken_OVERLAPS 279
#define FdoToken_TOUCHES 280
#define FdoToken_WITHIN 281
#define FdoToken_RELATE 282
#define FdoToken_IDENTIFIER 283
#define FdoToken_PARAMETER 284
#define FdoToken_STRING 285
#define FdoToken_INTEGER 286
#define FdoToken_INT64 287
#define FdoToken_DOUBLE 288
#define FdoToken_DATETIME 289
#define FdoToken_BLOB 290
#define FdoToken_CLOB 291
#define FdoToken_Add 292
#define FdoToken_Subtract 293
#define FdoToken_Multiply 294
#define FdoToken_Divide 295
#define FdoToken_Negate 296
#define FdoToken_EQ 297
#define FdoToken_NE 298
#define FdoToken_GT 299
#define FdoToken_GE 300
#define FdoToken_LT 301
#define FdoToken_LE 302
#define FdoToken_LeftParenthesis 303
#define FdoToken_RightParenthesis 304
#define FdoToken_LeftSquareBrackets 305
#define FdoToken_RightSquareBrackets 306
#define FdoToken_Comma 307
#define FdoToken_Dot 308
#define FdoToken_Colon 309
#define FdoToken_AS 310
#define FdoToken_BETWEEN 311
typedef union _FDO_CONSTRAINT_YYSTYPE
{
	FdoIDisposable*	m_node;		/* constraint parse tree node*/
	FdoInt32		m_id;		/* enumerations, keywords, ...*/
	FdoInt32		m_integer;	/* integer values (Int8, Int16, Int32 )*/
	FdoInt64		m_int64;	/* 64bit integer values */
	double			m_double;	/* floating point values (single(float), double)*/
	FdoString*		m_string;	/* string*/
	_FdoDateTime	m_datetime;	/* date time*/
} FDO_CONSTRAINT_YYSTYPE;
