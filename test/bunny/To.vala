    namespace bunny {
    /**
     *    To
     */
    public class To : Object {
        public Expectation parent; 
        public Should should;
        public bool invert = false;
        public To(Expectation parent) {
            this.parent = parent;
            should = new Should();
        }

        public To not { get { invert = true; return this; }}

        public void equal(Val expected) {
            var test = should.eq(parent.actual,  expected);
            Expectation.result = invert ? !test : test;
        }

        public void gt(Val expected) {
            var test = should.gt(parent.actual, expected);
            Expectation.result = invert ? !test : test;
        }

        public void ge(Val expected) {
            var test = should.ge(parent.actual, expected);
            Expectation.result = invert ? !test : test;
        }
        public void lt(Val expected) {
            var test = should.lt(parent.actual, expected);
            Expectation.result = invert ? !test : test;
        }
        public void le(Val expected) {
            var test = should.le(parent.actual, expected);
            Expectation.result = invert ? !test : test;
        }

    }
}