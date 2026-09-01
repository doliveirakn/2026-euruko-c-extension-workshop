# Ruby C Extensions Workshop

Learn to write C extensions for Ruby from the ground up — covering the full compile cycle, VALUE boxing and unboxing, defining classes and modules, managing instance variables, and using Ruby FFI.

## Table of Contents

1. [Exercise 1: Hello World / Initial Setup](./exercise1-hello-world)
2. [Exercise 2: VALUE Boxing & Unboxing](./exercise2-value-boxing)
3. [Exercise 3: Instance Variables](./exercise3-instance-variables)
4. [Exercise 4: Blocks & Calling Ruby Methods](./exercise4-blocks)
5. [Exercise 5: Classes, Modules, and Methods](./exercise5-classes-modules)
6. [Exercise 6: Exceptions & Memory Management](./exercise6-exceptions)
7. [Exercise 7: String & Array Manipulation](./exercise7-strings-arrays)
8. [Exercise 8: Ruby FFI](./exercise8-ffi)

## Prerequisites

- Ruby 3.x
- A C compiler (Clang on macOS, GCC on Linux)
- `make`
- Ruby development headers

## Setup — macOS

`xcode-select --install` installs Clang, make, and the SDK headers.

Install Ruby via rbenv or RVM — headers are bundled with the install.

Verify headers:

```sh
ruby -e "require 'rbconfig'; puts RbConfig::CONFIG['rubyhdrdir']"
```

## Setup — Linux (Ubuntu/Debian)

```sh
sudo apt-get install build-essential ruby-dev
```

For rbenv/rvm-managed Ruby: headers come with the install, no separate `ruby-dev` needed.

Verify with the same RbConfig command above:

```sh
ruby -e "require 'rbconfig'; puts RbConfig::CONFIG['rubyhdrdir']"
```

## Gem Setup

```sh
gem install bundler && bundle install
```

The FFI gem is needed for Exercise 8; minitest is used for tests across all exercises.

## How to Work Through This Workshop

Each exercise folder has its own README with step-by-step instructions. Work through them in order — the exercises build on each other conceptually, but each folder is fully self-contained so you can also jump to a specific topic.
