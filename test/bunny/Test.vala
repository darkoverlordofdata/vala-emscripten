namespace bunny {
    /**
     *    Test
     *    name & func of each test
     */
    public class Test : Object {
        public string name;
        public bool result;
        public unowned DelegateTest proc;
        public Test(string name, DelegateTest proc) {
            this.name = name;
            this.proc = proc;
            this.result = false;
        }
    }
}