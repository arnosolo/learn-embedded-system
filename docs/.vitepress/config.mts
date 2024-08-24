import { defineConfig } from 'vitepress'

// https://vitepress.dev/reference/site-config
export default defineConfig({
  base: '/learn-embedded-system/',
  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: 'Home', link: '/' },
      // { text: 'Examples', link: '/markdown-examples' }
    ],
    // sidebar: [
    //   {
    //     text: 'Examples',
    //     items: [
    //       { text: 'Markdown Examples', link: '/markdown-examples' },
    //       { text: 'Runtime API Examples', link: '/api-examples' }
    //     ]
    //   }
    // ],
    socialLinks: [
      { icon: 'github', link: 'https://github.com/arnosolo/learn-embedded-system' },
    ],
    logo: '/big-yellow.svg',
  },
  locales: {
    root: {
      label: 'English',
      lang: 'en',
      title: "Learn embedded system",
      description: "Here are some articles about embedded system.",
    },
    zh: {
      label: '简体中文',
      lang: 'zh-CN',
      link: '/zh/',
      title: '学习嵌入式系统',
      description: '这里有一些关于嵌入式系统的文章.'
    }
  },
})
