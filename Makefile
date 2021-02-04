##
## EPITECH PROJECT, 2021
## libjzon
## File description:
## Makefile automatically generated using Epine!
##

NAME = libjzon.a

all: libjzon.a
.PHONY: all

__NAME__SRCS := $(shell find -path './src/*.c')
__NAME__OBJS := $(filter %.c,$(__NAME__SRCS))
__NAME__OBJS := $(__NAME__OBJS:.c=.o)
__NAME__DEPS := $(__NAME__OBJS:.o=.d)
$(NAME) $(__NAME__OBJS): lib/libmy
$(NAME): CPPFLAGS :=
$(NAME): CPPFLAGS += -MD -MP
$(NAME): CPPFLAGS += -Iinclude
$(NAME): CPPFLAGS += -Ilib/libmy/include
$(NAME): CFLAGS :=
$(NAME): CFLAGS += -Wall
$(NAME): CFLAGS += -Wextra
$(NAME): CFLAGS += $(if DEBUG,-g3)
$(NAME): $(__NAME__OBJS)
	$(AR) rc $@ $(__NAME__OBJS)
-include $(__NAME__DEPS)

unit_tests_SRCS := $(shell find -path './tests/*.c')
unit_tests_OBJS := $(filter %.c,$(unit_tests_SRCS))
unit_tests_OBJS := $(unit_tests_OBJS:.c=.o)
unit_tests_DEPS := $(unit_tests_OBJS:.o=.d)
unit_tests $(unit_tests_OBJS): libjzon.a lib/libmy/libmy.a
unit_tests: CPPFLAGS :=
unit_tests: CPPFLAGS += -MD -MP
unit_tests: CPPFLAGS += -Iinclude
unit_tests: CPPFLAGS += -Ilib/libmy/include
unit_tests: CFLAGS :=
unit_tests: CFLAGS += -Wall
unit_tests: CFLAGS += -Wextra
unit_tests: CFLAGS += $(if DEBUG,-g3)
unit_tests: LDLIBS :=
unit_tests: LDLIBS += -ljzon
unit_tests: LDLIBS += -lmy
unit_tests: LDLIBS += -lcriterion
unit_tests: LDFLAGS :=
unit_tests: LDFLAGS += -L.
unit_tests: LDFLAGS += -Llib/libmy
unit_tests: LDFLAGS += -Wl,-rpath .
unit_tests: $(unit_tests_OBJS)
	$(CC) -o $@ $(unit_tests_OBJS) $(LDFLAGS) $(LDLIBS)
-include $(unit_tests_DEPS)

tests_run: unit_tests
	./unit_tests $(ARGS)
.PHONY: tests_run

clean:
	$(RM) $(__NAME__DEPS) $(__NAME__OBJS) $(unit_tests_DEPS) $(unit_tests_OBJS)
.PHONY: clean

fclean:
	$(RM) $(__NAME__DEPS) $(__NAME__OBJS) $(unit_tests_DEPS) $(unit_tests_OBJS)
	$(RM) $(NAME) unit_tests
	$(RM) unit_tests
.PHONY: fclean

re: fclean all
.PHONY: re

lib/libmy/libmy.a: lib/libmy
	$(MAKE) -C lib/libmy libmy.a clean
lib/libmy: lib
	git clone git@github.com:nasso/libmy lib/libmy
	rm -rf lib/libmy/.git
lib:
	mkdir lib
