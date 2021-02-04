local tek = require "@nasso/epine-tek/v0.1.0-alpha5"

tek:project "libjzon" {"libjzon.a"}

tek:static "libjzon.a" {
    prerequisites = {"lib/libmy"},
    incdirs = {"include", "lib/libmy/include"}
}

tek:binary "unit_tests" {
    prerequisites = {"libjzon.a", "lib/libmy/libmy.a"},
    srcs = {find "./tests/*.c"},
    incdirs = {"include", "lib/libmy/include"},
    libdirs = {".", "lib/libmy"},
    libs = {"jzon", "my", "criterion"}
}

return {
    tek:make(),
    epine.br,
    target "lib/libmy/libmy.a" {
        prerequisites = {"lib/libmy"},
        make("-C", "lib/libmy", "libmy.a", "clean")
    },
    target "lib/libmy" {
        prerequisites = {"lib"},
        "git clone git@github.com:nasso/libmy lib/libmy",
        "rm -rf lib/libmy/.git"
    },
    target "lib" {"mkdir lib"}
}
