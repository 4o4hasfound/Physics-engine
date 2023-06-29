#ifndef PULSAR_SETUP_INCLUDED
#define PULSAR_SETUP_INCLUDED

#include <limits>
#include <cstdint>
#include <type_traits>

#define PULSAR_ENABLE	1
#define PULSAR_DISABLE	0

////////////////////////////////////////////////////////
// C++ Version

// User defines: PULSAR_FORCE_CXX98, PULSAR_FORCE_CXX03, PULSAR_FORCE_CXX11, PULSAR_FORCE_CXX14, PULSAR_FORCE_CXX17, PULSAR_FORCE_CXX2A

// Compiler

#define PULSAR_COMPILER_UNKNOWN		0x00000000

// Intel
#define PULSAR_COMPILER_INTEL		0x00100000
#define PULSAR_COMPILER_INTEL14		0x00100040
#define PULSAR_COMPILER_INTEL15		0x00100050
#define PULSAR_COMPILER_INTEL16		0x00100060
#define PULSAR_COMPILER_INTEL17		0x00100070

// Visual C++ defines
#define PULSAR_COMPILER_VC			0x01000000
#define PULSAR_COMPILER_VC12			0x01000001
#define PULSAR_COMPILER_VC14			0x01000002
#define PULSAR_COMPILER_VC15			0x01000003
#define PULSAR_COMPILER_VC15_3			0x01000004
#define PULSAR_COMPILER_VC15_5			0x01000005
#define PULSAR_COMPILER_VC15_6			0x01000006
#define PULSAR_COMPILER_VC15_7			0x01000007
#define PULSAR_COMPILER_VC15_8			0x01000008
#define PULSAR_COMPILER_VC15_9			0x01000009
#define PULSAR_COMPILER_VC16			0x0100000A

// GCC defines
#define PULSAR_COMPILER_GCC			0x02000000
#define PULSAR_COMPILER_GCC46		0x020000D0
#define PULSAR_COMPILER_GCC47		0x020000E0
#define PULSAR_COMPILER_GCC48		0x020000F0
#define PULSAR_COMPILER_GCC49		0x02000100
#define PULSAR_COMPILER_GCC5			0x02000200
#define PULSAR_COMPILER_GCC6			0x02000300
#define PULSAR_COMPILER_GCC7			0x02000400
#define PULSAR_COMPILER_GCC8			0x02000500

// Clang
#define PULSAR_COMPILER_CLANG			0x20000000
#define PULSAR_COMPILER_CLANG34		0x20000050
#define PULSAR_COMPILER_CLANG35		0x20000060
#define PULSAR_COMPILER_CLANG36		0x20000070
#define PULSAR_COMPILER_CLANG37		0x20000080
#define PULSAR_COMPILER_CLANG38		0x20000090
#define PULSAR_COMPILER_CLANG39		0x200000A0
#define PULSAR_COMPILER_CLANG40		0x200000B0
#define PULSAR_COMPILER_CLANG41		0x200000C0
#define PULSAR_COMPILER_CLANG42		0x200000D0

// Force generic C++ compiler
#ifdef PULSAR_FORCE_COMPILER_UNKNOWN
#	define PULSAR_COMPILER	PULSAR_COMPILER_UNKNOWN

#elif defined(__INTEL_COMPILER)
#	if __INTEL_COMPILER >= 1700
#		define PULSAR_COMPILER	PULSAR_COMPILER_INTEL17
#	elif __INTEL_COMPILER >= 1600
#		define PULSAR_COMPILER	PULSAR_COMPILER_INTEL16
#	elif __INTEL_COMPILER >= 1500
#		define PULSAR_COMPILER	PULSAR_COMPILER_INTEL15
#	elif __INTEL_COMPILER >= 1400
#		define PULSAR_COMPILER	PULSAR_COMPILER_INTEL14
#	endif

// Clang
#elif defined(__clang__)
#	if defined(__apple_build_version__)
#		if (__clang_major__ < 6)
#			define PULSAR_COMPILER	PULSAR_COMPILER_UNKNOWN
#		elif __clang_major__ == 6 && __clang_minor__ == 0
#			define PULSAR_COMPILER	PULSAR_COMPILER_CLANG35
#		elif __clang_major__ == 6 && __clang_minor__ >= 1
#			define PULSAR_COMPILER	PULSAR_COMPILER_CLANG36
#		elif __clang_major__ >= 7
#			define PULSAR_COMPILER	PULSAR_COMPILER_CLANG37
#		endif
#	else
#		if ((__clang_major__ == 3) && (__clang_minor__ < 4)) || (__clang_major__ < 3)
#			error "PULSAR requires Clang 3.4 or higher"
#		elif __clang_major__ == 3 && __clang_minor__ == 4
#			define PULSAR_COMPILER	PULSAR_COMPILER_CLANG34
#		elif __clang_major__ == 3 && __clang_minor__ == 5
#			define PULSAR_COMPILER	PULSAR_COMPILER_CLANG35
#		elif __clang_major__ == 3 && __clang_minor__ == 6
#			define PULSAR_COMPILER	PULSAR_COMPILER_CLANG36
#		elif __clang_major__ == 3 && __clang_minor__ == 7
#			define PULSAR_COMPILER	PULSAR_COMPILER_CLANG37
#		elif __clang_major__ == 3 && __clang_minor__ == 8
#			define PULSAR_COMPILER	PULSAR_COMPILER_CLANG38
#		elif __clang_major__ == 3 && __clang_minor__ >= 9
#			define PULSAR_COMPILER	PULSAR_COMPILER_CLANG39
#		elif __clang_major__ == 4 && __clang_minor__ == 0
#			define PULSAR_COMPILER	PULSAR_COMPILER_CLANG40
#		elif __clang_major__ == 4 && __clang_minor__ == 1
#			define PULSAR_COMPILER	PULSAR_COMPILER_CLANG41
#		elif __clang_major__ == 4 && __clang_minor__ >= 2
#			define PULSAR_COMPILER	PULSAR_COMPILER_CLANG42
#		elif __clang_major__ >= 4
#			define PULSAR_COMPILER	PULSAR_COMPILER_CLANG42
#		endif
#	endif

// Visual C++
#elif defined(_MSC_VER)
#	if _MSC_VER >= 1920
#		define PULSAR_COMPILER	PULSAR_COMPILER_VC16
#	elif _MSC_VER >= 1916
#		define PULSAR_COMPILER	PULSAR_COMPILER_VC15_9
#	elif _MSC_VER >= 1915
#		define PULSAR_COMPILER	PULSAR_COMPILER_VC15_8
#	elif _MSC_VER >= 1914
#		define PULSAR_COMPILER	PULSAR_COMPILER_VC15_7
#	elif _MSC_VER >= 1913
#		define PULSAR_COMPILER	PULSAR_COMPILER_VC15_6
#	elif _MSC_VER >= 1912
#		define PULSAR_COMPILER	PULSAR_COMPILER_VC15_5
#	elif _MSC_VER >= 1911
#		define PULSAR_COMPILER	PULSAR_COMPILER_VC15_3
#	elif _MSC_VER >= 1910
#		define PULSAR_COMPILER	PULSAR_COMPILER_VC15
#	elif _MSC_VER >= 1900
#		define PULSAR_COMPILER	PULSAR_COMPILER_VC14
#	elif _MSC_VER >= 1800
#		define PULSAR_COMPILER	PULSAR_COMPILER_VC12
#	endif//_MSC_VER

// G++
#elif defined(__GNUC__) || defined(__MINGW32__)
#	if __GNUC__ >= 8
#		define PULSAR_COMPILER PULSAR_COMPILER_GCC8
#	elif __GNUC__ >= 7
#		define PULSAR_COMPILER PULSAR_COMPILER_GCC7
#	elif __GNUC__ >= 6
#		define PULSAR_COMPILER PULSAR_COMPILER_GCC6
#	elif __GNUC__ >= 5
#		define PULSAR_COMPILER PULSAR_COMPILER_GCC5
#	elif __GNUC__ == 4 && __GNUC_MINOR__ >= 9
#		define PULSAR_COMPILER PULSAR_COMPILER_GCC49
#	elif __GNUC__ == 4 && __GNUC_MINOR__ >= 8
#		define PULSAR_COMPILER PULSAR_COMPILER_GCC48
#	elif __GNUC__ == 4 && __GNUC_MINOR__ >= 7
#		define PULSAR_COMPILER PULSAR_COMPILER_GCC47
#	elif __GNUC__ == 4 && __GNUC_MINOR__ >= 6
#		define PULSAR_COMPILER PULSAR_COMPILER_GCC46
#	endif

#else
#	define PULSAR_COMPILER	PULSAR_COMPILER_UNKNOWN
#endif


// C++ Version
#define PULSAR_LANG_FLAG_CXX98		(1 << 1)
#define PULSAR_LANG_FLAG_CXX03		(1 << 2)
#define PULSAR_LANG_FLAG_CXX0X		(1 << 3)
#define PULSAR_LANG_FLAG_CXX11		(1 << 4)
#define PULSAR_LANG_FLAG_CXX14		(1 << 5)
#define PULSAR_LANG_FLAG_CXX17		(1 << 6)
#define PULSAR_LANG_FLAG_CXX2A		(1 << 7)
#define PULSAR_LANG_FLAG_CXXMS		(1 << 8)
#define PULSAR_LANG_FLAG_CXXGNU		(1 << 9)

#define PULSAR_LANG_CXX98		PULSAR_LANG_FLAG_CXX98
#define PULSAR_LANG_CXX03		(PULSAR_LANG_CXX98 | PULSAR_LANG_FLAG_CXX03)
#define PULSAR_LANG_CXX0X		(PULSAR_LANG_CXX03 | PULSAR_LANG_FLAG_CXX0X)
#define PULSAR_LANG_CXX11		(PULSAR_LANG_CXX0X | PULSAR_LANG_FLAG_CXX11)
#define PULSAR_LANG_CXX14		(PULSAR_LANG_CXX11 | PULSAR_LANG_FLAG_CXX14)
#define PULSAR_LANG_CXX17		(PULSAR_LANG_CXX14 | PULSAR_LANG_FLAG_CXX17)
#define PULSAR_LANG_CXX2A		(PULSAR_LANG_CXX17 | PULSAR_LANG_FLAG_CXX2A)
#define PULSAR_LANG_CXXMS		PULSAR_LANG_FLAG_CXXMS
#define PULSAR_LANG_CXXGNU		PULSAR_LANG_FLAG_CXXGNU


#if (defined(PULSAR_FORCE_CXX_UNKNOWN))
#	define PULSAR_LANG	0
#elif (defined(PULSAR_FORCE_CXX2A))
#	define PULSAR_LANG	PULSAR_LANG_CXX2A
#	define PULSAR_LANG_STL11_FORCED
#elif (defined(PULSAR_FORCE_CXX17))
#	define PULSAR_LANG	PULSAR_LANG_CXX17
#	define PULSAR_LANG_STL11_FORCED
#elif (defined(PULSAR_FORCE_CXX14))
#	define PULSAR_LANG	PULSAR_LANG_CXX14
#	define PULSAR_LANG_STL11_FORCED
#elif (defined(PULSAR_FORCE_CXX11))
#	define PULSAR_LANG	PULSAR_LANG_CXX11
#	define PULSAR_LANG_STL11_FORCED
#elif (defined(PULSAR_FORCE_CXX03))
#	define PULSAR_LANG	PULSAR_LANG_CXX03
#elif (defined(PULSAR_FORCE_CXX98))
#	define PULSAR_LANG	PULSAR_LANG_CXX98
#else
#	if (PULSAR_COMPILER & PULSAR_COMPILER_VC) && defined(_MSVC_LANG)
#		if PULSAR_COMPILER >= PULSAR_COMPILER_VC15_7
#			define PULSAR_LANG_PLATFORM	_MSVC_LANG
#		elif PULSAR_COMPILER >= PULSAR_COMPILER_VC15
#			if _MSVC_LANG > 201402L
#				define PULSAR_LANG_PLATFORM		201402L
#			else
#				define PULSAR_LANG_PLATFORM		_MSVC_LANG
#			endif
#		else
#			define PULSAR_LANG_PLATFORM		0
#		endif
#	else
#		define PULSAR_LANG_PLATFORM		0
#	endif

#	if __cplusplus > 201703L || PULSAR_LANG_PLATFORM > 201703L
#		define PULSAR_LANG	PULSAR_LANG_CXX2A
#	elif __cplusplus == 201703L || PULSAR_LANG_PLATFORM == 201703L
#		define PULSAR_LANG	PULSAR_LANG_CXX17
#	elif __cplusplus == 201402L || __cplusplus == 201500L || PULSAR_LANG_PLATFORM == 201402L
#		define PULSAR_LANG	PULSAR_LANG_CXX14
#	elif __cplusplus == 201103L || PULSAR_LANG_PLATFORM == 201103L
#		define PULSAR_LANG	PULSAR_LANG_CXX11
#	elif defined(__INTEL_CXX11_MODE__) || defined(_MSC_VER) || defined(__GXX_EXPERIMENTAL_CXX0X__)
#		define PULSAR_LANG	PULSAR_LANG_CXX0X
#	elif __cplusplus == 199711L
#		define PULSAR_LANG	PULSAR_LANG_CXX98
#	else
#		define PULSAR_LANG 0
#	endif
#endif

////////////////////////////////////////////////////////
// FORCE_INLINE

#if (PULSAR_COMPILER & PULSAR_COMPILER_VC)
#	define PULSAR_INLINE		__forceinline
#elif (PULSAR_COMPILER & PULSAR_COMPILER_GCC) || (PULSAR_COMPILER & PULSAR_COMPILER_CLANG)
#	define PULSAR_INLINE		inline __attribute((always_inline))
#else
#	define PULSAR_INLINE		inline
#endif

////////////////////////////////////////////////////////
// Initializer lists

#if PULSAR_COMPILER & PULSAR_COMPILER_CLANG
#	define PULSAR_HAS_INITIALIZER_LISTS		__has_feature(cxx_generalized_initializers)
#elif PULSAR_LANG & PULSAR_LANG_FLAG_CXX11
#	define PULSAR_HAS_INITIALIZER_LISTS		1
#else
#	define PULSAR_HAS_INITIALIZER_LISTS ((PULSAR_LANG & PULSAR_LANG_FLAG_CXX0X) && (\
		((PULSAR_COMPILER & PULSAR_COMPILER_VC) && (PULSAR_COMPILER >= PULSAR_COMPILER_VC15)) || \
		((PULSAR_COMPILER & PULSAR_COMPILER_INTEL) && (PULSAR_COMPILER >= PULSAR_COMPILER_INTEL14))
#endif

////////////////////////////////////////////////////////
// Constant expressions

#if (PULSAR_COMPILER & PULSAR_COMPILER_CLANG)
#	define PULSAR_HAS_CONSTEXPR __has_feature(cxx_relaxed_constexpr)
#elif (PULSAR_LANG & PULSAR_LANG_FLAG_CXX14)
#	define PULSAR_HAS_CONSTEXPR 1
#else
#	define PULSAR_HAS_CONSTEXPR ((PULSAR_LANG & PULSAR_LANG_FLAG_CXX0X) && PULSAR_HAS_INITIALIZER_LISTS && (\
		((PULSAR_COMPILER & PULSAR_COMPILER_INTEL) && (PULSAR_COMPILER >= PULSAR_COMPILER_INTEL17)) || \
		((PULSAR_COMPILER & PULSAR_COMPILER_VC) && (PULSAR_COMPILER >= PULSAR_COMPILER_VC15))))
#endif

#if PULSAR_HAS_CONSTEXPR
#	define PULSAR_CONSTEXPR constexpr
#else
#	define PULSAR_CONSTEXPR
#endif

////////////////////////////////////////////////////////
// Length type

#define PULSAR_LENGTH_INT		1
#define PULSAR_LENGTH_SIZET		2

#ifdef PULSAR_FORCE_SIZET_LENGTH
#	define PULSAR_CONFIG_LENGTH_TYPE		PULSAR_LENGTH_SIZET
#else
#	define PULSAR_CONFIG_LENGTH_TYPE		PULSAR_LENGTH_INT
#endif

////////////////////////////////////////////////////////
// Template Aliases

#if PULSAR_COMPILER & PULSAR_COMPILER_CLANG
#	define PULSAR_HAS_TEMPLATE_ALIASES __has_feature(cxx_alias_templates)
#elif PULSAR_LANG & PULSAR_LANG_FLAG_CXX11
#	define PULSAR_HAS_TEMPLATE_ALIASES 1
#else
#	define PULSAR_HAS_TEMPLATE_ALIASES ((PULSAR_LANG & PULSAR_LANG_FLAG_CXX0X) && (\
		((PULSAR_COMPILER & PULSAR_COMPILER_INTEL)) || \
		((PULSAR_COMPILER & PULSAR_COMPILER_VC) && (PULSAR_COMPILER >= PULSAR_COMPILER_VC12))
#endif

////////////////////////////////////////////////////////
// Use default

#if PULSAR_COMPILER & PULSAR_COMPILER_CLANG
#	define PULSAR_HAS_DEFAULTED_FUNCTIONS	__has_feature(cxx_defaulted_functions)
#elif PULSAR_LANG & PULSAR_LANG_FLAG_CXX11
#	define PULSAR_HAS_DEFAULTED_FUNCTIONS	1
#else
#	define PULSAR_HAS_DEFAULTED_FUNCTIONS ((PULSAR_LANG & PULSAR_LANG_FLAG_CXX0X) && (\
		((PULSAR_COMPILER & PULSAR_COMPILER_VC) && (PULSAR_COMPILER >= PULSAR_COMPILER_VC12)) || \
		((PULSAR_COMPILER & PULSAR_COMPILER_INTEL))
#endif

#if PULSAR_HAS_DEFAULTED_FUNCTIONS
#	define PULSAR_DEFAULT = default
#	define PULSAR_CONFIG_USE_DEFAULT_FUNCTION PULSAR_ENABLE
#else
#	define PULSAR_DEFAULT
#	define PULSAR_CONFIG_USE_DEFAULT_FUNCTION PULSAR_DISABLE
#endif

////////////////////////////////////////////////////////
// Has CXX11 STL

#if PULSAR_COMPILER & PULSAR_COMPILER_CLANG
#	if (PULSAR_LANG & PULSAR_LANG_CXX11_FLAG) || defined(PULSAR_LANG_STL11_FORCED))
#		define PULSAR_HAS_CXX11_STL 1
#	else
#		define PULSAR_HAS_CXX11_STL 0
#	endif
#elif PULSAR_LANG & PULSAR_LANG_FLAG_CXX11
#	define PULSAR_HAS_CXX11_STL 1
#else
#	define PULSAR_HAS_CXX11_STL ((PULSAR_LANG & PULSAR_LANG_FLAG_CXX0X) && (\
		((PULSAR_COMPILER & PULSAR_COMPILER_GCC) && (PULSAR_COMPILER >= PULSAR_COMPILER_GCC48)) || \
		((PULSAR_COMPILER & PULSAR_COMPILER_VC) && (PULSAR_COMPILER >= PULSAR_COMPILER_VC12))
#endif


////////////////////////////////////////////////////////
// Explicit

#define PULSAR_EXPLICIT explicit

namespace Pulsar {
	template<typename T>
	using numeric_limits = std::numeric_limits<T>;

	using std::uint8_t;
	using std::uint16_t;
	using std::uint32_t;
	using std::uint64_t;

	using std::int8_t;
	using std::int16_t;
	using std::int32_t;
	using std::int64_t;

	using std::size_t;

	using std::make_unsigned;

	// Decimal
#	ifdef PULSAR_FORCE_DOUBLE_PRECISION
		using Decimal = double;
#	else
		using Decimal = float;
#	endif

	// Length type
#	if PULSAR_CONFIG_LENGTH_TYPE == PULSAR_LENGTH_SIZET
		using length_t = size_t;
#	else
		using length_t = int32_t;
#	endif

#define ToDecimal(x)  static_cast<Decimal>(x)

	PULSAR_CONSTEXPR Decimal DecimalMax =	numeric_limits<Decimal>::max();
	PULSAR_CONSTEXPR Decimal DecimalMin =	numeric_limits<Decimal>::min();

	PULSAR_CONSTEXPR Decimal PI =			Decimal(3.14159265358979323846264338327950);
	PULSAR_CONSTEXPR Decimal PI_DOUBLE =	Decimal(6.283185307179586);

	PULSAR_CONSTEXPR Decimal DEG_TO_RAD =	Decimal(0.01745329251994329576923690768489);
	PULSAR_CONSTEXPR Decimal RAD_TO_DEG =	Decimal(57.295779513082320876798154814105);

	PULSAR_CONSTEXPR Decimal Sqrt2 =		Decimal(1.41421356237309504880168);
}

#endif