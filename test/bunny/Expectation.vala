namespace bunny {
    /**
     *    Expectation
     */
    public class Expectation : Object {
        public Val actual;
        public To to;
        public static bool result;
        public Expectation(Val actual) {
            this.actual = actual;
            to = new To(this);
        }
    }
}