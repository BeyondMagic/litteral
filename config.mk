#---------------------------------------------
# -- Program defaults.

DIST = distribution
COMPILER = g++ -std=c++2b
FILE = source/main.cpp

#---------------------------------------------
# C++ standard version

#FLAGS := $(FLAGS)

#---------------------------------------------
# -- Libs.

#LIBS := -lfmt

#---------------------------------------------
# -- Debugging.

FLAGS := $(FLAGS) -ggdb

#---------------------------------------------
# -- Warnings we *need* to see.

FLAGS := $(FLAGS) -Ofast

EXTRA := $(EXTRA) -Wall

EXTRA := $(EXTRA) -Werror

EXTRA := $(EXTRA) -Wextra

EXTRA := $(EXTRA) -pedantic

EXTRA := $(EXTRA) -Wconversion

EXTRA := $(EXTRA) -Wsign-conversion

# Signed integer overflow is defined to wrap-around (behavior of Java, release-mode Rust, and unchecked C#). GCC and Clang provide non-standard settings to do this already
EXTRA := $(EXTRA) -fwrapv

# All uninitialized variables of automatic storage duration and fundamental or trivially-constructible types are zero-initialized, and all other variables of automatic storage storage and initialized via a defaulted constructor will be initialized by applying this same rule to their non-static data members. All uninitialized pointers will be initialized to nullptr. (approximately the behavior of Java). State of padding is unspecified. GCC and Clang have a similar setting available now
EXTRA := $(EXTRA) -ftrivial-auto-var-init=zero

# Direct use of any form new, delete, std::construct_at, std::uninitialized_move, manual destructor calls, etc are prohibited. Manual memory and object lifetime management is relegated to unsafe code.

# Messing with aliasing is prohibited: no reinterpret_cast or __restrict language extensions allowed. Bytewise inspection of data can be accomplished through std::span<std::byte> with some modification

# Intentionally invoking undefined behavior is also not allowed - this means no [[assume()]], std::assume_aligned, or std::unreachable().

# Only calls to functions with well-defined behavior for all inputs is allowed. This is considerably more restrictive than it may appear. This requires a new function attribute, [[trusted]] would be my preference but a [[safe]] function attribute proposal already exists for aiding in interop with Rust etc and I see no point in making two function attributes with identical purposes of marking functions as okay to be called from safe code.

# any use of a potentially moved-from object before re-assignment is not allowed? I'm not sure how easy it is to enforce this one.

# No pointer arithmetic allowed.

# no implicit narrowing conversions allowed (static_cast is required there)

#------------------------------------------------
# -- Sanitisers.

EXTRA := $(EXTRA) -fsanitize-undefined-trap-on-error

EXTRA := $(EXTRA) -fsanitize-address-use-after-scope

EXTRA := $(EXTRA) -fsanitize=address
EXTRA := $(EXTRA),undefined

# Those are only for clang++.
#EXTRA := $(EXTRA),nullability
#EXTRA := $(EXTRA),implicit-integer-truncation
#EXTRA := $(EXTRA),implicit-integer-arithmetic-value-change
#EXTRA := $(EXTRA),implicit-conversion
#EXTRA := $(EXTRA),integer
