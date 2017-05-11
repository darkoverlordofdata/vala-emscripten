/**
 *
 *     ___
 *    | _ )_  _ _ _  _ _ _  _
 *    | _ \ || | ' \| ' \ || |
 *    |___/\_,_|_||_|_||_\_, |
 *                       |__/
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

/**
 * 
 * 


public class TestExample : bunny.UnitTest {
  public TestExample() {
    describe("TestExample");
    it("is a 42!", () => {
      new Expectation<int>(42).to.match(32+10);
    });
  }
  public static int main(string[] args) {
    new TestExample().run();
    return 0;
  }
}
 * 
 */

namespace bunny {
    const string __bunny__= """
  bunny unit test suite v0.0.2

          /\ /\
          \/_\/
          ('.')
         (     )

    It's no ordinary rabbit

""";


    /** @type Signature of Test function */
    public delegate void DelegateTest();

	[SimpleType]
	[Immutable]
	public struct IFixture { 
		public unowned DelegateTest setup;
		public unowned DelegateTest teardown;
	}

    /**
     * Bunny - Vala Unit Testing
     * inspired by Chai
     *
     */
    public class UnitTest: Object {
        public int passed = 0;
        public int failed = 0;
        public string name = "";
        public Should should;
        public List<Test> tests = new List<Test>();
        public IFixture allFixture;
        public IFixture eachFixture;
        public bool allIsSet = false;
        public bool eachIsSet = false;

        public void setEach(IFixture fixture) {
            eachFixture = fixture;
            eachIsSet = true;
        }

        public void setAll(IFixture fixture) {
            allFixture = fixture;
            allIsSet = true;
        }

        public void describe(string name) {
            this.name = name;
        }

        public void it(string name, DelegateTest proc) {
            tests.append(new Test(name, proc));
        }

        public Expectation expect(Val actual) {
            return new Expectation(actual);
        }

        public void run() {

			stdout.printf("Run!\n");

            passed = 0;
            failed = 0;

            stdout.printf(__bunny__);
            stdout.printf("\t%s\n---------------------------------\n", name);
            if (allIsSet) allFixture.setup();
            foreach (var test in tests) {
                if (eachIsSet) eachFixture.setup();
                  test.proc();
                  if (Expectation.result) {
                      passed++;
                      stdout.printf("PASS <=> %s\n", test.name);
                  } else {
                      failed++;
                      stdout.printf("FAIL <=> %s\n", test.name);
                  }
                if (eachIsSet) eachFixture.teardown();
            }
            if (allIsSet) allFixture.teardown();
            stdout.printf("---------------------------------\n");
            stdout.printf("    <====> Pass: %d\n", passed);
            stdout.printf("    <====> Fail: %d\n\n", failed);
        }

    }
}