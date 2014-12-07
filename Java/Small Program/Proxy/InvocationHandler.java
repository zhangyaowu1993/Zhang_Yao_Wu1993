package com.ysu.zyw;

import java.lang.reflect.Method;

/**
 * Created by zhang_yao_wu1993 on 14/12/6.
 */
public interface InvocationHandler
{
    void invoke(Object o, Method m);
}
