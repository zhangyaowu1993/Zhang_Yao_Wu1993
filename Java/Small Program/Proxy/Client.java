package com.ysu.zyw;

/**
 * Created by zhang_yao_wu1993 on 14/12/6.
 * 实现了动态代理
 * 代理对象 实现了 Moveable 接口的 Tank
 * 代理生成类 Proxy 会自动生成实现了 Moveable 接口和有一个 Handler 的动态代理
 * 调用动态代理的方法会先去执行 Handler 的方法在去反射被代理对象的方法
 */
public class Client
{
    public static void main(String[] args) throws Exception
    {
        Moveable m = (Moveable)Proxy.getNewProxy(Moveable.class, new TimeInvocationHandler(new Tank()));
        m.move();
    }
}
