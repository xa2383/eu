import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class MD5 {

    public static String getMd5(String input) {
        try {
            MessageDigest msgDst = MessageDigest.getInstance("MD5");
            byte[] msgArr = msgDst.digest(input.getBytes());
            BigInteger bi = new BigInteger(1, msgArr);
            String hshtxt = bi.toString(16);

            while (hshtxt.length() < 32) {
                hshtxt = "0" + hshtxt;
            }
            return hshtxt;
        } catch (NoSuchAlgorithmException abc) {
            throw new RuntimeException(abc);
        }
    }

    public static void main(String[] argvs) {
        String str = "ssitise";
        String hash = getMd5(str);
        str = "'isedept'";
        System.out.println("The HashCode Generated for " + str + " is: " + hash);
    }
}
