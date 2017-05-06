[Compact]
[CCode (cname = "FILE", free_function = "fclose", cheader_filename = "stdio.h")]
public class FILE {
    [CCode (cname = "fopen")]
    public static FILE? open (string path, string mode);

    [CCode (cname = "fgets", instance_pos = -1)]
    public unowned string? gets (char[] s);
}
