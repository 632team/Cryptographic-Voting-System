package com.util;

import java.io.*;
import java.security.*;
import java.security.interfaces.*;
import java.security.spec.*;

import javax.crypto.*;

public class RSAEncrypt {
	/** 
     * �ֽ�����ת�ַ���ר�ü��� 
     */  
    private static final char[] HEX_CHAR = {'0', '1', '2', '3', '4', '5', '6',  
            '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };  
    
    /** 
     * ���������Կ�� 
     */  
    public static String[] genKeyPair() {
        // KeyPairGenerator���������ɹ�Կ��˽Կ�ԣ�����RSA�㷨���ɶ���  
        KeyPairGenerator keyPairGen = null;
        try {
            keyPairGen = KeyPairGenerator.getInstance("RSA");
        } catch (NoSuchAlgorithmException e) {  
            // TODO Auto-generated catch block  
            e.printStackTrace();
        }  
        // ��ʼ����Կ������������Կ��СΪ96-1024λ  
        keyPairGen.initialize(1024,new SecureRandom());
        // ����һ����Կ�ԣ�������keyPair��  
        KeyPair keyPair = keyPairGen.generateKeyPair();
        // �õ�˽Կ  
        RSAPrivateKey privateKey = (RSAPrivateKey) keyPair.getPrivate();
        // �õ���Կ  
        RSAPublicKey publicKey = (RSAPublicKey) keyPair.getPublic();
        String[] ret = new String[2];
        try {
            // �õ���Կ�ַ���  
            ret[0] = Base64.encode(publicKey.getEncoded());
            // �õ�˽Կ�ַ���  
            ret[1] = Base64.encode(privateKey.getEncoded());
            // ����Կ��д�뵽�ļ�  
//            FileWriter pubfw = new FileWriter("publicKey.keystore");
//            FileWriter prifw = new FileWriter("privateKey.keystore");
//            BufferedWriter pubbw = new BufferedWriter(pubfw);
//            BufferedWriter pribw = new BufferedWriter(prifw);
//            pubbw.write(publicKeyString);
//            pribw.write(privateKeyString);
//            pubbw.close();
//            pubfw.close();
//            pribw.close();
//            prifw.close();
        } catch (Exception e) {  
            e.printStackTrace();  
        }
        return ret;
    }  
	
    /** 
     * ���ļ����������м��ع�Կ 
     *  
     * @param in 
     *            ��Կ������ 
     * @throws Exception 
     *             ���ع�Կʱ�������쳣 
     */  
    public static String loadPublicKeyByFile(String path) throws Exception {  
        try {  
            BufferedReader br = new BufferedReader(new FileReader(path  
                    + "/publicKey.keystore"));  
            String readLine = null;  
            StringBuilder sb = new StringBuilder();  
            while ((readLine = br.readLine()) != null) {  
                sb.append(readLine);  
            }  
            br.close();  
            return sb.toString();  
        } catch (IOException e) {  
            throw new Exception("��Կ��������ȡ����");  
        } catch (NullPointerException e) {  
            throw new Exception("��Կ������Ϊ��");  
        }  
    }  
  
    /** 
     * ���ַ����м��ع�Կ 
     *  
     * @param publicKeyStr 
     *            ��Կ�����ַ��� 
     * @throws Exception 
     *             ���ع�Կʱ�������쳣 
     */  
    public static RSAPublicKey loadPublicKeyByStr(String publicKeyStr)  
            throws Exception {  
        try {  
            byte[] buffer = Base64.decode(publicKeyStr);  
            KeyFactory keyFactory = KeyFactory.getInstance("RSA");  
            X509EncodedKeySpec keySpec = new X509EncodedKeySpec(buffer);  
            return (RSAPublicKey) keyFactory.generatePublic(keySpec);  
        } catch (NoSuchAlgorithmException e) {  
            throw new Exception("�޴��㷨");  
        } catch (InvalidKeySpecException e) {  
            throw new Exception("��Կ�Ƿ�");  
        } catch (NullPointerException e) {  
            throw new Exception("��Կ����Ϊ��");  
        }  
    }  
  
    /** 
     * ���ļ��м���˽Կ 
     *  
     * @param keyFileName 
     *            ˽Կ�ļ��� 
     * @return �Ƿ�ɹ� 
     * @throws Exception 
     */  
    public static String loadPrivateKeyByFile(String path) throws Exception {  
        try {  
            BufferedReader br = new BufferedReader(new FileReader(path  
                    + "/privateKey.keystore"));  
            String readLine = null;  
            StringBuilder sb = new StringBuilder();  
            while ((readLine = br.readLine()) != null) {  
                sb.append(readLine);  
            }  
            br.close();  
            return sb.toString();  
        } catch (IOException e) {  
            throw new Exception("˽Կ���ݶ�ȡ����");  
        } catch (NullPointerException e) {  
            throw new Exception("˽Կ������Ϊ��");  
        }  
    }  
  
    public static RSAPrivateKey loadPrivateKeyByStr(String privateKeyStr)  
            throws Exception {  
        try {  
            byte[] buffer = Base64.decode(privateKeyStr);  
            PKCS8EncodedKeySpec keySpec = new PKCS8EncodedKeySpec(buffer);  
            KeyFactory keyFactory = KeyFactory.getInstance("RSA");  
            return (RSAPrivateKey) keyFactory.generatePrivate(keySpec);  
        } catch (NoSuchAlgorithmException e) {  
            throw new Exception("�޴��㷨");  
        } catch (InvalidKeySpecException e) {  
            throw new Exception("˽Կ�Ƿ�");  
        } catch (NullPointerException e) {  
            throw new Exception("˽Կ����Ϊ��");  
        }  
    }  
  
    /** 
     * ��Կ���ܹ��� 
     *  
     * @param publicKey 
     *            ��Կ 
     * @param plainTextData 
     *            �������� 
     * @return 
     * @throws Exception 
     *             ���ܹ����е��쳣��Ϣ 
     */  
    public static byte[] encrypt(RSAPublicKey publicKey, byte[] plainTextData)  
            throws Exception {  
        if (publicKey == null) {  
            throw new Exception("���ܹ�ԿΪ��, ������");  
        }  
        Cipher cipher = null;  
        try {  
            // ʹ��Ĭ��RSA  
            cipher = Cipher.getInstance("RSA");  
            // cipher= Cipher.getInstance("RSA", new BouncyCastleProvider());  
            cipher.init(Cipher.ENCRYPT_MODE, publicKey);  
            byte[] output = cipher.doFinal(plainTextData);  
            return output;  
        } catch (NoSuchAlgorithmException e) {  
            throw new Exception("�޴˼����㷨");  
        } catch (NoSuchPaddingException e) {  
            e.printStackTrace();  
            return null;  
        } catch (InvalidKeyException e) {  
            throw new Exception("���ܹ�Կ�Ƿ�,����");  
        } catch (IllegalBlockSizeException e) {  
            throw new Exception("���ĳ��ȷǷ�");  
        } catch (BadPaddingException e) {  
            throw new Exception("������������");  
        }  
    }  
  
    /** 
     * ˽Կ���ܹ��� 
     *  
     * @param privateKey 
     *            ˽Կ 
     * @param plainTextData 
     *            �������� 
     * @return 
     * @throws Exception 
     *             ���ܹ����е��쳣��Ϣ 
     */  
    public static byte[] encrypt(RSAPrivateKey privateKey, byte[] plainTextData)  
            throws Exception {  
        if (privateKey == null) {  
            throw new Exception("����˽ԿΪ��, ������");  
        }  
        Cipher cipher = null;  
        try {  
            // ʹ��Ĭ��RSA  
            cipher = Cipher.getInstance("RSA");  
            cipher.init(Cipher.ENCRYPT_MODE, privateKey);  
            byte[] output = cipher.doFinal(plainTextData);  
            return output;  
        } catch (NoSuchAlgorithmException e) {  
            throw new Exception("�޴˼����㷨");  
        } catch (NoSuchPaddingException e) {  
            e.printStackTrace();  
            return null;  
        } catch (InvalidKeyException e) {  
            throw new Exception("����˽Կ�Ƿ�,����");  
        } catch (IllegalBlockSizeException e) {  
            throw new Exception("���ĳ��ȷǷ�");  
        } catch (BadPaddingException e) {  
            throw new Exception("������������");  
        }  
    }  
  
    /** 
     * ˽Կ���ܹ��� 
     *  
     * @param privateKey 
     *            ˽Կ 
     * @param cipherData 
     *            �������� 
     * @return ���� 
     * @throws Exception 
     *             ���ܹ����е��쳣��Ϣ 
     */  
    public static byte[] decrypt(RSAPrivateKey privateKey, byte[] cipherData)  
            throws Exception {  
        if (privateKey == null) {  
            throw new Exception("����˽ԿΪ��, ������");  
        }  
        Cipher cipher = null;  
        try {  
            // ʹ��Ĭ��RSA  
            cipher = Cipher.getInstance("RSA");  
            // cipher= Cipher.getInstance("RSA", new BouncyCastleProvider());  
            cipher.init(Cipher.DECRYPT_MODE, privateKey);  
            byte[] output = cipher.doFinal(cipherData);  
            return output;  
        } catch (NoSuchAlgorithmException e) {  
            throw new Exception("�޴˽����㷨");  
        } catch (NoSuchPaddingException e) {  
            e.printStackTrace();  
            return null;  
        } catch (InvalidKeyException e) {  
            throw new Exception("����˽Կ�Ƿ�,����");  
        } catch (IllegalBlockSizeException e) {  
            throw new Exception("���ĳ��ȷǷ�");  
        } catch (BadPaddingException e) {  
            throw new Exception("������������");  
        }  
    }  
  
    /** 
     * ��Կ���ܹ��� 
     *  
     * @param publicKey 
     *            ��Կ 
     * @param cipherData 
     *            �������� 
     * @return ���� 
     * @throws Exception 
     *             ���ܹ����е��쳣��Ϣ 
     */  
    public static byte[] decrypt(RSAPublicKey publicKey, byte[] cipherData)  
            throws Exception {  
        if (publicKey == null) {  
            throw new Exception("���ܹ�ԿΪ��, ������");  
        }  
        Cipher cipher = null;  
        try {  
            // ʹ��Ĭ��RSA  
            cipher = Cipher.getInstance("RSA");  
            // cipher= Cipher.getInstance("RSA", new BouncyCastleProvider());  
            cipher.init(Cipher.DECRYPT_MODE, publicKey);  
            byte[] output = cipher.doFinal(cipherData);  
            return output;  
        } catch (NoSuchAlgorithmException e) {  
            throw new Exception("�޴˽����㷨");  
        } catch (NoSuchPaddingException e) {  
            e.printStackTrace();  
            return null;  
        } catch (InvalidKeyException e) {  
            throw new Exception("���ܹ�Կ�Ƿ�,����");  
        } catch (IllegalBlockSizeException e) {  
            throw new Exception("���ĳ��ȷǷ�");  
        } catch (BadPaddingException e) {  
            throw new Exception("������������");  
        }  
    }  
  
    /** 
     * �ֽ�����תʮ�������ַ��� 
     *  
     * @param data 
     *            �������� 
     * @return ʮ���������� 
     */  
    public static String byteArrayToString(byte[] data) {  
        StringBuilder stringBuilder = new StringBuilder();  
        for (int i = 0; i < data.length; i++) {  
            // ȡ���ֽڵĸ���λ ��Ϊ�����õ���Ӧ��ʮ�����Ʊ�ʶ�� ע���޷�������  
            stringBuilder.append(HEX_CHAR[(data[i] & 0xf0) >>> 4]);  
            // ȡ���ֽڵĵ���λ ��Ϊ�����õ���Ӧ��ʮ�����Ʊ�ʶ��  
            stringBuilder.append(HEX_CHAR[(data[i] & 0x0f)]);  
            if (i < data.length - 1) {  
                stringBuilder.append(' ');  
            }  
        }  
        return stringBuilder.toString();  
    }
}
