package com.ysu.zyw;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

/**
 * Created by zhang_yao_wu1993 on 14/12/6.
 */
public class TimeInvocationHandler implements InvocationHandler
{
    Moveable target;

    TimeInvocationHandler(Moveable target)
    {
        this.target = target;
    }

    @Override
    public void invoke(Object o, Method m)
    {
        long start = System.currentTimeMillis();
        System.out.println("Before Process");
        try
        {
            m.invoke(target);
            Thread.sleep((int)(Math.random() * 1000));
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        
        long end = System.currentTimeMillis();
        System.out.println("After Process");
        System.out.println(end - start);
    }
}
