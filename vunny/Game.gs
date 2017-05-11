[indent=4]
uses
    Bosco


init
    stdout.printf("Application started\n")
    var game = new Game()
    game.OnExecute()

class Game : AbstractGame

    const WALKING_ANIMATION_FRAMES:int = 4
    const SCREEN_WIDTH:int = 640
    const SCREEN_HEIGHT:int = 480
    frame:int = 0

    spriteClips:array of SDL.Rectangle = new array of SDL.Rectangle[4]
    spriteSheetTexture:Texture
    backgroundTexture:Texture

    construct()
        name = "GameFoo"
        width = SCREEN_WIDTH
        height = SCREEN_HEIGHT
        running = true

    /**
     *  OnLoop
     *
     * Process the physics
     */
    def override OnLoop()
        frame++
        if frame / WALKING_ANIMATION_FRAMES >= WALKING_ANIMATION_FRAMES
            frame = 0

    /**
     *  OnRender
     *
     * Render the screen
     */
    def override OnRender()
        renderer.set_draw_color(0xFF, 0xFF, 0xFF, SDL.Alpha.OPAQUE)
        renderer.clear()

        var currentClip = spriteClips[frame / WALKING_ANIMATION_FRAMES]
        spriteSheetTexture.render(renderer, (SCREEN_WIDTH - currentClip.w) / 2, (SCREEN_HEIGHT - currentClip.h) / 2, currentClip)
        backgroundTexture.render(renderer, 0, 0)
        renderer.present()

    /**
     *  OnInit
     *
     * load assets
     */
    def override OnInit():bool
        if super.OnInit()

            var imgInitFlags = SDLImage.InitFlags.PNG
            var initResult = SDLImage.init(imgInitFlags)
            if (initResult & imgInitFlags) != imgInitFlags
                stdout.printf("SDL_image could not initialize! SDL_image Error: %s\n", SDLImage.get_error())
                return false

            spriteSheetTexture = Texture.fromFile(renderer, "resources/foo.png")
            if spriteSheetTexture == null
                stdout.puts("Failed to load walking animation texture!\n")
                return false
            else
                spriteClips[0] = {0, 0, 64, 205}
                spriteClips[1] = {64, 0, 64, 205}
                spriteClips[2] = {128, 0, 64, 205}
                spriteClips[3] = {196, 0, 64, 205}

            backgroundTexture = Texture.fromFile(renderer, "resources/background.png")
            if backgroundTexture == null
                stdout.puts("Failed to load background texture image!\n")
                return false

        return true

    /**
     *  OnEvent
     *
     * Handle events
     */
    def override OnEvent(e:SDL.Event)
        if e.type == SDL.EventType.QUIT
            running = false

    /**
     *  OnCleanup
     *
     * release assets
     */
    def override OnCleanup()
        SDL.quit()
        SDLImage.quit()


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
