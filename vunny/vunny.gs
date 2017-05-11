/**
 *
 *     ___
 *    | _ )_  _ _ _  _ _ _  _
 *    | _ \ || | ' \| ' \ || |
 *    |___/\_,_|_||_|_||_\_, |
 *     __   __           |__/
 *     \ \ / /  _ _ _  _ _ _  _
 *      \ V / || | ' \| ' \ || |
 *       \_/ \_,_|_||_|_||_\_, |
 *                         |__/
 *
 *
 *        /\ /\
 *        \/_\/
 *        ('.')
 *       (     )
 *
 *
 * Simple Testing Framework for Vala/Genie
 *    by Dark Overlord of Data
 *
 *
 *
 *
 *    Copyright 2016 Bruce Davidson
 */
[indent=4]
const __bunny__:string = """
  bunny vunny test suite v0.0.1

          /\ /\
          \/_\/
          ('.')
         (     )

    It's no ordinary rabbit

"""

namespace Bunny
    /** @type Signature of Test function */
    delegate DelegateTest()
    delegate DelegateFunc():bool


    /**
     *    Vunny - Vala Unit Testing
     * inspired by Chai
     *
     *  GObject is a requirement to provice init/final blocks for test
     */
    class Vunny : GLib.Object
        passed:int=0
        failed:int=0
        name:string = ""
        should:Should
        tests:list of Test = new list of Test

        construct()
            should = new Should()

        def describe(name:string)
            this.name = name

        def expect(actual:Value):Expectation
            return new Expectation(actual)

        def test(name:string, proc:DelegateTest)
            tests.add(new Test(name, proc))

        def it(name:string, func:DelegateFunc)
            tests.add(new Test.withFunc(name, func))

        def run()

            passed = 0
            failed = 0

            print __bunny__
            print "\t%s\n---------------------------------", name
            for test in tests
                if test.hasReturn
                  if test.func()
                      passed++
                      print "PASS <=> %s", test.name
                  else
                      failed++
                      print "FAIL <=> %s", test.name
                else
                  test.proc()
                  if Expectation.result
                      passed++
                      print "PASS <=> %s", test.name
                  else
                      failed++
                      print "FAIL <=> %s", test.name

            print "---------------------------------"
            print "    <====> Pass: %d", passed
            print "    <====> Fail: %d\n\n\033[0m", failed

    /**
     *    Expectation
     */
    class Expectation
        actual:Value
        to:To
        result:static bool
        construct(actual:Value)
            this.actual = actual
            to = new To(this)

    /**
     *    Test
     *    name & func of each test
     */
    class Test
        name: string
        result: bool
        hasReturn: bool
        proc: unowned DelegateTest
        func: unowned DelegateFunc
        construct(name:string, proc:DelegateTest)
            this.name = name
            this.proc = proc
            this.result = false
            this.hasReturn = false
        construct withFunc(name:string, func:DelegateFunc)
            this.name = name
            this.func = func
            this.result = false
            this.hasReturn = true

    /**
     *    To
     */
    class To
        parent: Expectation
        should: Should
        invert: bool = false
        construct(parent:Expectation)
            this.parent = parent
            should = new Should()

        // def @not():To
        prop @not: To
            get
                invert = true
                return this

        def equal(expected:Value)
            var test = should.eq(parent.actual, expected)
            Expectation.result = invert ? !test : test

        def gt(expected:Value)
            var test = should.gt(parent.actual.get_string(), expected.get_string())
            Expectation.result = invert ? !test : test

        def ge(expected:Value)
            var test = should.ge(parent.actual, expected)
            Expectation.result = invert ? !test : test

        def lt(expected:Value)
            var test = should.lt(parent.actual, expected)
            Expectation.result = invert ? !test : test

        def le(expected:Value)
            var test = should.le(parent.actual, expected)
            Expectation.result = invert ? !test : test

        def match(expected:Value)
            var test = should.match(parent.actual.get_string(), expected.get_string())
            Expectation.result = invert ? !test : test


    /**
     *    Should
     */
    class Should
        def match(actual:string, expected:string):bool
            var result = false
            try
                var r = new Regex(expected)
                result = r.match(actual)
            except e: RegexError
                stdout.printf("Error %s\n", e.message)

            return result

        /**
         *    eq - check equality
         *
         * @param expected pattern
         * @param actual value
         * @returns true or false
         */
        def eq(actual:Value, expected:Value):bool
            var test = false
            var t = expected.type()

            if expected.type_name() == actual.type_name()
                if t.is_a(typeof(string))
                    test = expected.get_string() == actual.get_string()

                else if t.is_a(typeof(bool))
                    test = expected.get_boolean() == actual.get_boolean()

                else if t.is_a(typeof(int))
                    test = expected.get_int() == actual.get_int()

                else if t.is_a(typeof(long))
                    test = expected.get_long() == actual.get_long()

                else if t.is_a(typeof(char))
                    test = expected.get_char() == actual.get_char()

                else if t.is_a(typeof(double))
                    test = expected.get_double() == actual.get_double()

                else if t.is_a(typeof(float))
                    test = expected.get_float() == actual.get_float()

            return test

        /**
         *    ne - check inequality
         *
         * @param expected pattern
         * @param actual value
         * @returns true or false
         */
        def ne(actual:Value, expected:Value):bool
            var test = false
            var t = expected.type()
            if expected.type_name() == actual.type_name()
                if t.is_a(typeof(string))
                    test = expected.get_string() != actual.get_string()

                else if t.is_a(typeof(bool))
                    test = expected.get_boolean() != actual.get_boolean()

                else if t.is_a(typeof(int))
                    test = expected.get_int() != actual.get_int()

                else if t.is_a(typeof(long))
                    test = expected.get_long() != actual.get_long()

                else if t.is_a(typeof(char))
                    test = expected.get_char() != actual.get_char()

                else if t.is_a(typeof(double))
                    test = expected.get_double() != actual.get_double()

                else if t.is_a(typeof(float))
                    test = expected.get_float() != actual.get_float()


            return test

        /**
         *    le - check less than or equal
         *
         * @param expected pattern
         * @param actual value
         * @returns true or false
         */
        def le(actual:Value, expected:Value):bool
            var test = false
            var t = expected.type()
            if expected.type_name() == actual.type_name()
                if t.is_a(typeof(string))
                    test = expected.get_string() <= actual.get_string()

                else if t.is_a(typeof(int))
                    test = expected.get_int() <= actual.get_int()

                else if t.is_a(typeof(long))
                    test = expected.get_long() <= actual.get_long()

                else if t.is_a(typeof(char))
                    test = expected.get_char() <= actual.get_char()

                else if t.is_a(typeof(double))
                    test = expected.get_double() <= actual.get_double()

                else if t.is_a(typeof(float))
                    test = expected.get_float() <= actual.get_float()


            return test

        /**
         *    lt - check less than
         *
         * @param expected pattern
         * @param actual value
         * @returns true or false
         */
        def lt(actual:Value, expected:Value):bool
            var test = false
            var t = expected.type()
            if expected.type_name() == actual.type_name()
                if t.is_a(typeof(string))
                    test = expected.get_string() < actual.get_string()

                else if t.is_a(typeof(int))
                    test = expected.get_int() < actual.get_int()

                else if t.is_a(typeof(long))
                    test = expected.get_long() < actual.get_long()

                else if t.is_a(typeof(char))
                    test = expected.get_char() < actual.get_char()

                else if t.is_a(typeof(double))
                    test = expected.get_double() < actual.get_double()

                else if t.is_a(typeof(float))
                    test = expected.get_float() < actual.get_float()


            return test

        /**
         *    gt - check greater than
         *
         * @param expected pattern
         * @param actual value
         * @returns true or false
         */
        def gt(actual:Value, expected:Value):bool
            var test = false
            var t = expected.type()
            if expected.type_name() == actual.type_name()
                if t.is_a(typeof(string))
                    test = expected.get_string() > actual.get_string()

                else if t.is_a(typeof(int))
                    test = expected.get_int() > actual.get_int()

                else if t.is_a(typeof(long))
                    test = expected.get_long() > actual.get_long()

                else if t.is_a(typeof(char))
                    test = expected.get_char() > actual.get_char()

                else if t.is_a(typeof(double))
                    test = expected.get_double() > actual.get_double()

                else if t.is_a(typeof(float))
                    test = expected.get_float() > actual.get_float()


            return test

        /**
         *    ge - check greater than or equal
         *
         * @param expected pattern
         * @param actual value
         * @returns true or false
         */
        def ge(actual:Value, expected:Value):bool
            var test = false
            var t = expected.type()
            if expected.type_name() == actual.type_name()
                if t.is_a(typeof(string))
                    test = expected.get_string() >= actual.get_string()

                else if t.is_a(typeof(int))
                    test = expected.get_int() >= actual.get_int()

                else if t.is_a(typeof(long))
                    test = expected.get_long() >= actual.get_long()

                else if t.is_a(typeof(char))
                    test = expected.get_char() >= actual.get_char()

                else if t.is_a(typeof(double))
                    test = expected.get_double() >= actual.get_double()

                else if t.is_a(typeof(float))
                    test = expected.get_float() >= actual.get_float()


            return test