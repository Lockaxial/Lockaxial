package com.androidex.plugins;

import android.app.Activity;
import android.util.Log;

import com.androidex.hwuitls.Base16;
import com.androidex.hwuitls.Base64Utils;

import org.json.JSONObject;

import java.io.ByteArrayInputStream;
import java.math.BigInteger;
import java.security.InvalidKeyException;
import java.security.KeyFactory;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.NoSuchProviderException;
import java.security.PublicKey;
import java.security.SignatureException;
import java.security.cert.CertificateException;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.security.spec.DSAPublicKeySpec;
import java.security.spec.RSAPublicKeySpec;

public class kkaexparams {
    static
    {
        try {
            System.loadLibrary("Lockaxial");
        } catch (UnsatisfiedLinkError e) {
            Log.d("AEXP", "Aexp_Params library not found!");
        }
    }
    Activity ctx = null;
    public kkaexparams(Activity _ctx){
        ctx = _ctx;
    }

    /**
     * 从AndroidEx参数中读取参数值的函数
     * @param param
     * @return
     */
    private String getAndroidExParameter(String param)
    {
        return getAndroidExParam(param);
    }

    /**
     * 设置AndroidEx参数的值
     * @param param
     * @param value
     */
    private void setAndroidExParameter(String param, String value)
    {
        setAndroidExParam(param,value);
    }

    /**
     * 获取设备的GUID
     * @return  字符串表示的GUID
     */
    public String get_uuid()
    {
        return getUUID();
    }

    /**
     * 获取存储的密码的hash值
     * @return  返回base16编码的密码的hash值
     */
    public String get_pass()
    {
        return getPass();
    }

    /**
     * 设置密码的函数，提供的参数是密码明文。
     * @param value     用户输入的明文密码
     */
    public void set_pass(String value)
    {
        try {
            MessageDigest md5 = MessageDigest.getInstance("MD5");
            md5.update(value.getBytes());
            String hash = Base16.encode(md5.digest());
            //取得密码的hash值然后存储
            setPass(hash);
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 判断是否已经设置了密码
     * @return
     */
    public boolean has_pass()
    {
        String pass = get_pass();

        if(pass == null)return false;
        return pass.equalsIgnoreCase("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF") == false;
    }

    public void clear_pass()
    {
        set_pass("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF");
    }

    /**
     * 判断提供的参数是否是没有设置过密码的
     * @param pass  base16编码的密码的hash值
     * @return
     */
    public boolean has_pass(String pass)
    {
        return pass.equalsIgnoreCase("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF") == false;
    }

    /**
     * 校验密码与存储的是否一致
     * @param pass  密码的明文
     * @return  是否与存储的一致？
     */
    public boolean verify_pass(String pass)
    {
        String passhash = get_pass();

        if(has_pass(passhash)) {
            //存储了密码
            try {
                MessageDigest md5 = MessageDigest.getInstance("MD5");
                md5.update(pass.getBytes());
                String hash = Base16.encode(md5.digest());
                return hash.equalsIgnoreCase(passhash.trim());
            } catch (NoSuchAlgorithmException e) {
                Log.e("AEXP",e.getLocalizedMessage(),e);
                //e.printStackTrace();
            } catch (Exception e) {
                Log.e("AEXP",e.getLocalizedMessage(),e);
                e.printStackTrace();
            }
        }
        return false;
    }

    public String get_certsn()
    {
        return getCertsn();
    }

    public void set_certsn(String value)
    {
        setCertsn(value);
    }

    public String get_p7cert()
    {
        return getP7cert();
    }

    public void set_p7cert(String value)
    {
        setP7cert(value);
    }

    public String get_noafter()
    {
        return getNoafter();
    }

    public String get_nobefore()
    {
        return getNobefore();
    }


    public String get_state()
    {
        return getState();
    }

    public String get_userinfo()
    {
        return getUserinfo();
    }

    public void set_userinfo(String value)
    {
        setUserinfo(value);
    }

    static public JSONObject parse_p7cert(String p7cert)
    {
        byte[] p7cert_decode = null;
        try {
            JSONObject result = new JSONObject();
            p7cert_decode = Base64Utils.decode(p7cert);
            ByteArrayInputStream bIn = new ByteArrayInputStream(p7cert_decode);
            CertificateFactory certificatefactory = CertificateFactory.getInstance("X.509");
            X509Certificate cert = (X509Certificate)certificatefactory.generateCertificate(bIn);

            result.put("ver",cert.getVersion());
            result.put("sn",Base16.encode(cert.getSerialNumber().toByteArray()).toUpperCase());
            result.put("saName",cert.getSigAlgName());
            result.put("oid",cert.getSigAlgOID());
            result.put("type",cert.getType());
            result.put("issuer",cert.getIssuerDN().toString());
            result.put("notbefore",cert.getNotBefore().getTime());
            result.put("notafter",cert.getNotAfter().getTime());
            result.put("subject",cert.getSubjectDN());
            result.put("signature",Base64Utils.encode(cert.getSignature()));

            /*
            System.out.format("证书版本:%s\n",cert.getVersion());
            System.out.format("序列号:%s\n", Base16.encode(cert.getSerialNumber().toByteArray()));
            System.out.format("算法标识:%s,%s,%s\n", cert.getSigAlgName(), cert.getSigAlgOID(), cert.getType());
            System.out.format("签发者:%s\n", cert.getIssuerDN().toString());
            DateFormat dformat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
            Date notBefore = new Date(cert.getNotBefore().getTime());
            System.out.format("开始时间:%s\n",dformat.format(notBefore));
            Date notAfter = new Date(cert.getNotAfter().getTime());
            System.out.format("结束时间:%s\n",dformat.format(notAfter));
            System.out.format("主体名:%s\n", cert.getSubjectDN());
            System.out.format("签名值:%s\n", Base64Utils.encode(cert.getSignature()));
            */
            PublicKey pukinfo = cert.getPublicKey();
            try {
                cert.verify(pukinfo);
                result.put("status", 1);
            }catch (CertificateException e){
                e.printStackTrace();
                result.put("status",0);
            }catch (NoSuchAlgorithmException e){
                e.printStackTrace();
                result.put("status",0);
            }catch (InvalidKeyException e){
                e.printStackTrace();
                result.put("status",0);
            }catch (NoSuchProviderException e){
                e.printStackTrace();
                result.put("status",0);
            }catch (SignatureException e){
                e.printStackTrace();
                result.put("status",0);
            }

            /*System.out.format("\t标识符:%s\n",pukinfo.getAlgorithm());
            String pukinfo_toString = pukinfo.toString();
            String pukinfo_getEncoded = Base64Utils.encode(pukinfo.getEncoded());
            System.out.format("\t公钥值:getFormat=%s\ntoString[%d]=%s\ngetEncode[%d]=%s\n",
                    pukinfo.getFormat(),
                    pukinfo_toString.length(),pukinfo_toString,
                    pukinfo.getEncoded().length,pukinfo_getEncoded
                    );
                    */
            String algorithm = pukinfo.getAlgorithm(); // 获取算法
            result.put("algorithm",algorithm);
            if(algorithm.equalsIgnoreCase("RSA")) {
                KeyFactory keyFact = KeyFactory.getInstance(algorithm);
                RSAPublicKeySpec keySpec = (RSAPublicKeySpec)keyFact.getKeySpec(pukinfo, RSAPublicKeySpec.class);
                BigInteger pm = keySpec.getModulus();
                result.put("length",pm.toString(2).length());
                result.put("publickey",Base64Utils.encode((pm.toByteArray())));
                //System.out.format("PublicKey[%d]=%s\n",pm.toString(2).length(),Base64Utils.encode((pm.toByteArray())));
                return result;
            }else{
                KeyFactory keyFact = KeyFactory.getInstance(algorithm);
                DSAPublicKeySpec keySpec = (DSAPublicKeySpec)keyFact.getKeySpec(pukinfo, DSAPublicKeySpec.class);
                BigInteger pm = keySpec.getP();
                result.put("length",pm.toString(2).length());
                result.put("publickey",Base64Utils.encode((pm.toByteArray())));
                //System.out.format("PublicKey[%d]=%s\n",pm.toString(2).length(),Base64Utils.encode((pm.toByteArray())));
                return result;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
    //jni 相关函数
    public native String    getAndroidExParam(String address);
    public native int       setAndroidExParam(String address,String hexValue);
    public native String    getUUID();
    public native String    getPass();
    public native int       setPass(String hexPass);
    public native String    getCertsn();
    public native int       setCertsn(String hexValue);
    public native String    getP7cert();
    public native int       setP7cert(String hexValue);
    public native String    getNoafter();
    public native String    getNobefore();
    public native String    getState();
    public native String    getUserinfo();
    public native int       setUserinfo(String hexValue);
}