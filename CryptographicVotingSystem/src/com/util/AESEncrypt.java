package com.util;

import java.io.UnsupportedEncodingException;
import java.security.*;
import java.security.SecureRandom;
import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;

public class AESEncrypt {
	/**
     * AES�����ַ���
     * 
     * @param content
     *            ��Ҫ�����ܵ��ַ���
     * @param password
     *            ������Ҫ������
     * @return ����
     */
    public static byte[] encrypt(String content, String password) {
        try {
            KeyGenerator kgen = KeyGenerator.getInstance("AES");// ����AES��Key������

            kgen.init(128, new SecureRandom(password.getBytes()));// �����û�������Ϊ�������ʼ����
                                                                    // 128λ��key������
            //����û��ϵ��SecureRandom�����ɰ�ȫ��������У�password.getBytes()�����ӣ�ֻҪ������ͬ�����о�һ�������Խ���ֻҪ��password����

            SecretKey secretKey = kgen.generateKey();// �����û����룬����һ����Կ

            byte[] enCodeFormat = secretKey.getEncoded();// ���ػ��������ʽ����Կ���������Կ��֧�ֱ��룬�򷵻�
                                                            // null��

            SecretKeySpec key = new SecretKeySpec(enCodeFormat, "AES");// ת��ΪAESר����Կ

            Cipher cipher = Cipher.getInstance("AES");// ����������

            byte[] byteContent = content.getBytes("utf-8");

            cipher.init(Cipher.ENCRYPT_MODE, key);// ��ʼ��Ϊ����ģʽ��������

            byte[] result = cipher.doFinal(byteContent);// ����

            return result;

        } catch (NoSuchPaddingException e) {
            e.printStackTrace();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        } catch (InvalidKeyException e) {
            e.printStackTrace();
        } catch (IllegalBlockSizeException e) {
            e.printStackTrace();
        } catch (BadPaddingException e) {
            e.printStackTrace();
        }
        return null;
    }
    
    /**
     * ����AES���ܹ����ַ���
     * 
     * @param content
     *            AES���ܹ���������
     * @param password
     *            ����ʱ������
     * @return ����
     */
    public static byte[] decrypt(byte[] content, String password) {
        try {
            KeyGenerator kgen = KeyGenerator.getInstance("AES");// ����AES��Key������
            kgen.init(128, new SecureRandom(password.getBytes()));
            SecretKey secretKey = kgen.generateKey();// �����û����룬����һ����Կ
            byte[] enCodeFormat = secretKey.getEncoded();// ���ػ��������ʽ����Կ
            SecretKeySpec key = new SecretKeySpec(enCodeFormat, "AES");// ת��ΪAESר����Կ
            Cipher cipher = Cipher.getInstance("AES");// ����������
            cipher.init(Cipher.DECRYPT_MODE, key);// ��ʼ��Ϊ����ģʽ��������
            byte[] result = cipher.doFinal(content);  
            return result; // ����   
            
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        } catch (NoSuchPaddingException e) {
            e.printStackTrace();
        } catch (InvalidKeyException e) {
            e.printStackTrace();
        } catch (IllegalBlockSizeException e) {
            e.printStackTrace();
        } catch (BadPaddingException e) {
            e.printStackTrace();
        }
        return null;
    }
}
