namespace bunny {
    /**
     *    Should
     */
    public class Should: Object {
        /**
         *    eq - check equality
         *
         * @param expected pattern
         * @param actual value
         * @returns true or false
         */
        public bool eq(Val actual, Val expected) {
            return expected.eq(actual);
        }
        /**
         *    ne - check inequality
         *
         * @param expected pattern
         * @param actual value
         * @returns true or false
         */
        public bool ne(Val actual, Val expected) {
            return expected.ne(actual);
        }
        /**
         *    le - check less than or equal
         *
         * @param expected pattern
         * @param actual value
         * @returns true or false
         */
        public bool le(Val actual, Val expected) {
            return expected.le(actual);
        }
        /**
         *    lt - check less than
         *
         * @param expected pattern
         * @param actual value
         * @returns true or false
         */
        public bool lt(Val actual, Val expected) {
            return expected.lt(actual);
        }
        /**
         *    gt - check greater than
         *
         * @param expected pattern
         * @param actual value
         * @returns true or false
         */
        public bool gt(Val actual, Val expected) {
            return expected.gt(actual);
        }
        /**
         *    ge - check greater than or equal
         *
         * @param expected pattern
         * @param actual value
         * @returns true or false
         */
        public bool ge(Val actual, Val expected) {
            return expected.ge(actual);
        }

    }
}