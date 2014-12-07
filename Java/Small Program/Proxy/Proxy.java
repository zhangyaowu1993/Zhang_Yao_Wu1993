package com.ysu.zyw;

import javax.tools.JavaCompiler;
import javax.tools.StandardJavaFileManager;
import javax.tools.ToolProvider;
import java.io.File;
import java.io.FileWriter;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.net.URL;
import java.net.URLClassLoader;

/**
 * Created by zhang_yao_wu1993 on 14/12/6.
 */
public class Proxy
{
    private static final String nr = "\n";


    public static Object getNewProxy(Class inf, InvocationHandler ih) throws Exception
    {
        Method[] methods = inf.getMethods();
        String str_method = new String();
        for(Method m : methods)
        {
            str_method +=
                    "    @Override" + nr +
                    "    public void " + m.getName() + "()" + nr +
                    "    {" + nr +
                    "        try" + nr +
                    "        {" + nr +
                    "            Method me = " + inf.getName() + ".class.getMethod(\"" + m.getName() + "\");" + nr +
                    "            ih.invoke(this, me);" + nr +
                    "        }" + nr +
                    "        catch(Exception e) { }" + nr +
                    "    }";
        }

        String str =
                        "package com.ysu.zyw;" + nr +
                        "import java.lang.reflect.Method;" + nr +
                        "public class $Proxy implements " + inf.getName() + nr +
                        "{" + nr +
                        "    private com.ysu.zyw.InvocationHandler ih;" + nr +
                        "    public $Proxy(com.ysu.zyw.InvocationHandler ih)" + nr +
                        "    {" + nr +
                        "        super();" + nr +
                        "        this.ih = ih;" + nr +
                        "    }" + nr +
                        str_method + nr +
                        "}";


        // 拼代码
        String fileName = System.getProperty("user.dir") + "/JavaModules/src/com/ysu/zyw/$Proxy.java";
        System.out.println(fileName);
        File f = new File(fileName);
        FileWriter fw = new FileWriter(f);
        fw.write(str);
        fw.flush();
        fw.close();

        // 编译
        JavaCompiler jc = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager sjfm = jc.getStandardFileManager(null, null, null);
        Iterable units = sjfm.getJavaFileObjects(fileName);
        JavaCompiler.CompilationTask task = jc.getTask(null, sjfm, null, null, null, units);
        task.call();

        // 载入
        URL[] url = new URL[] { new URL("file:/" + System.getProperty("user.dir") + "/JavaModules/src") };
        System.out.println("123" + url[0]);
        URLClassLoader loader = new URLClassLoader(url);
        Class proxy = loader.loadClass("com.ysu.zyw.$Proxy");

        Constructor ctr = proxy.getConstructor(InvocationHandler.class);
        Object obj = ctr.newInstance(ih);

        return obj;
    }
}
