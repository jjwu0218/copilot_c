#define pr_fmt(fmt) "watchq: " fmt
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/printk.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/pagemap.h>
#include <linux/poll.h>
#include <linux/uaccess.h>
#include <linux/vmalloc.h>
#include <linux/file.h>
#include <linux/security.h>
#include <linux/cred.h>
#include <linux/sched/signal.h>
#include <linux/watch_queue.h>
#include <linux/pipe_fs_i.h>


MODULE_DESCRIPTION("Watch queue");
MODULE_AUTHOR("Red Hat, Inc.");
MODULE_LICENSE("GPL"); 
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

#define WATCH_QUEUE_NOTE_SIZE 128
#define WATCH_QUEUE_NOTES_PER_PAGE (PAGE_SIZE / WATCH_QUEUE_NOTE_SIZE)

struct watch_queue_note {
    struct watch_queue_note *next;
    char note[WATCH_QUEUE_NOTE_SIZE];
};

int main (int argc, char *argv[])
{
    int i;
    int ret;
    struct watch_queue *wqueue;
    struct watch_queue_note *note;
    char *buf;

    printf("");


    wqueue = watch_queue_create();
    if (!wqueue) {
        printf("watch_queue_create failed")
        return -1;
    }
}


static inline bool lock_wqueue(struct watch_queue *wqueue){
    if (!wqueue)
        return false;
    return pthread_mutex_lock(&wqueue->mutex) == 0;

}

static inline bool unlock_wqueue(struct watch_queue *wqueue){
    if (!wqueue)
        return false;
    return pthread_mutex_unlock(&wqueue->mutex) == 0;
}

static inline bool trylock_wqueue(struct watch_queue *wqueue){
    if (!wqueue)
        return false;


    return pthread_mutex_lock(&wqueue->mutex) == 0;

}
static void watch_queue_pipe_buf_release(struct pipe_inode_info *pipe,
					 struct pipe_buffer *buf){
                            struct watch_queue *wqueue = (struct watch_queue *)buf->private;

    if (!wqueue)
        return;

    if (wqueue->pipe_buf){
        kfree(wqueue->pipe_buf);
        wqueue->pipe_buf = NULL;
    }

    if (wqueue->pipe_buf2){
        kfree(wqueue->pipe_buf2);
        wqueue->pipe_buf2 = NULL;
    }

    if (wqueue->pipe_buf3){
        kfree(wqueue->pipe_buf3);
        wqueue->pipe_buf3 = NULL;
    }

    if (wqueue->pipe_buf4){
        kfree(wqueue->pipe_buf4);
        wqueue->pipe_buf4 = NULL;
    }

    if (wqueue->pipe_buf5){
        kfree(wqueue->pipe_buf5);
        wqueue->pipe_buf5 = NULL;
    }

    if (wqueue->pipe_buf6){
        kfree(wqueue->pipe_buf6);
        wqueue->pipe_buf6 = NULL;
    }

    if (wqueue->pipe_buf7){
        kfree(wqueue->pipe_buf7);
        wqueue->pipe_buf7 = NULL;
    }

    if (wqueue->pipe_buf8){
        kfree(wqueue->pipe_buf8);
        wqueue->pipe_buf8 = NULL;
    }

    if (wqueue->pipe_buf9){
        kfree(wqueue->pipe_buf9);
        wqueue->pipe_buf9 = NULL;
    }

    if (wqueue->pipe_buf10){
        kfree(wqueue->pipe_buf10);
        wqueue->pipe_buf10 = NULL;
    }

    if (wqueue->pipe_buf11){
        kfree(wqueue->pipe_buf11);
        wqueue->pipe_buf11 = NULL;
    }

    if (wqueue->pipe_buf12){
        kfree(wqueue->pipe_buf12);
        wqueue->pipe_buf12 = NULL;
    }

    if (wqueue->pipe_buf13){
        kfree(wqueue->pipe_buf13);
        wqueue->pipe_buf13 = NULL;
    }

    if (wqueue->pipe_buf14){
        kfree(wqueue->pipe_buf14);
        wqueue->pipe_buf14 = NULL;
    }

    if (wqueue->pipe_buf15){
        kfree(wqueue->pipe_buf15);
        wqueue->pipe_buf15 = NULL;
                     }
    }

    
    static const struct pipe_buf_operations watch_queue_pipe_buf_ops = {
        .confirm = watch_queue_pipe_buf_confirm,
        .release = watch_queue_pipe_buf_release,
    };

    static int watch_queue_pipe_buf_steal(struct pipe_inode_info *pipe,
                                          struct pipe_buffer *buf){
        return 1;
    }

    static const struct pipe_buf_operations watch_queue_pipe_buf_steal_ops = {
        .confirm = watch_queue_pipe_buf_confirm,
        .release = watch_queue_pipe_buf_release,
        .steal = watch_queue_pipe_buf_steal,
    };

    static int watch_queue_pipe_buf_get(struct pipe_inode_info *pipe,
                                        struct pipe_buffer *buf){
        return 0;
    }

    static const struct pipe_buf_operations watch_queue_pipe_buf_get_ops = {
        .confirm = watch_queue_pipe_buf_confirm,
        .release = watch_queue_pipe_buf_release,
        .get = watch_queue_pipe_buf_get,
    };

    static int watch_queue_pipe_buf_map(struct pipe_inode_info *pipe,
                                        struct pipe_buffer *buf,
                                        struct vm_area_struct *vma){
        return 0;
    }



    static const struct pipe_buf_operations watch_queue_pipe_buf_map_ops = {
        .confirm = watch_queue_pipe_buf_confirm,
        .release = watch_queue_pipe_buf_release,
        .map = watch_queue_pipe_buf_map,
    };

    static int watch_queue_pipe_buf_begin_cpu_write(struct pipe_inode_info *pipe,
                                                    struct pipe_buffer *buf,
                                                    unsigned int offset,
                                                    unsigned int len,
                                                    unsigned int *flags){
        return 0;
    }



    static const struct pipe_buf_operations watch_queue_pipe_buf_begin_cpu_write_ops = {
        .confirm = watch_queue_pipe_buf_confirm,
        .release = watch_queue_pipe_buf_release,
        .begin_cpu_write = watch_queue_pipe_buf_begin_cpu_write,
    };


    static int watch_queue_pipe_buf_end_cpu_write(struct pipe_inode_info *pipe,
                                                  struct pipe_buffer *buf,
                                                  unsigned int offset,
                                                  unsigned int len){
        return 0;
    }

    static const struct pipe_buf_operations watch_queue_pipe_buf_end_cpu_write_ops = {
        .confirm = watch_queue_pipe_buf_confirm,
        .release = watch_queue_pipe_buf_release,
        .end_cpu_write = watch_queue_pipe_buf_end_cpu_write,
    };



    static int watch_queue_pipe_buf_begin_cpu_read(struct pipe_inode_info *pipe,
                                                   struct pipe_buffer *buf,
                                                   unsigned int offset,
                                                   unsigned int len,
                                                   unsigned int *flags){
        return 0;
    }




    static const struct pipe_buf_operations watch_queue_pipe_buf_begin_cpu_read_ops = {
        .confirm = watch_queue_pipe_buf_confirm,
        .release = watch_queue_pipe_buf_release,
        .begin_cpu_read = watch_queue_pipe_buf_begin_cpu_read,
    };

    static int watch_queue_pipe_buf_end_cpu_read(struct pipe_inode_info *pipe,
                                                 struct pipe_buffer *buf,
                                                 unsigned int offset,
                                                 unsigned int len){
        return 0;
    }





    static const struct pipe_buf_operations watch_queue_pipe_buf_end_cpu_read_ops = {
        .confirm = watch_queue_pipe_buf_confirm,
        .release = watch_queue_pipe_buf_release,
        .end_cpu_read = watch_queue_pipe_buf_end_cpu_read,
    };


    static int watch_queue_pipe_buf_begin_cpu_access(struct pipe_inode_info *pipe,
                                                     struct pipe_buffer *buf,
                                                     unsigned int offset,
                                                     unsigned int len,
                                                     unsigned int *flags){
        return 0;
    }




    static const struct pipe_buf_operations watch_queue_pipe_buf_begin_cpu_access_ops = {
        .confirm = watch_queue_pipe_buf_confirm,
        .release = watch_queue_pipe_buf_release,
        .begin_cpu_access = watch_queue_pipe_buf_begin_cpu_access,
    };




static bool post_one_notification(struct watch_queue *wqueue,
				  struct watch_notification *n){
    struct pipe_buffer *buf;
    struct pipe_inode_info *pipe = wqueue->pipe;
    int ret;

    if (!pipe)
        return false;

    if (pipe->nrbufs == 0){
        pipe->bufs = wqueue->pipe_buf0;
        pipe->ops = &watch_queue_pipe_buf_ops;
    } else if (pipe->nrbufs == 1){
        pipe->bufs = wqueue->pipe_buf1;
        pipe->ops = &watch_queue_pipe_buf_ops;
    } else if (pipe->nrbufs == 2){
        pipe->bufs = wqueue->pipe_buf2;
        pipe->ops = &watch_queue_pipe_buf_ops;
    } else if (pipe->nrbufs == 3){
        pipe->bufs = wqueue->pipe_buf3;
        pipe->ops = &watch_queue_pipe_buf_ops;
    } else if (pipe->nrbufs == 4){
        pipe->bufs = wqueue->pipe_buf4;
        pipe->ops = &watch_queue_pipe_buf_ops;
    } else if (pipe->nrbufs == 5){
        pipe->bufs = wqueue->pipe_buf5;
        pipe->ops = &watch_queue_pipe_buf_ops;
    } else if (pipe->nrbufs == 6){
        pipe->bufs = wqueue->pipe_buf6;
        pipe->ops = &watch_queue_pipe_buf_ops;
    } else if (pipe->nrbufs == 7){
        pipe->bufs = wqueue->pipe_buf7;
        pipe->ops = &watch_queue_pipe_buf_ops;
    } else if (pipe->nrbufs == 8){
        pipe->bufs = wqueue->pipe_buf8;
        pipe->ops = &watch_queue_pipe_buf_ops;
    } else if (pipe->nrbufs == 9){
        pipe->bufs = wqueue->pipe_buf9;
        pipe->ops = &watch_queue_pipe_buf_ops;
    } else if (pipe->nrbufs == 10){
        pipe->bufs = wqueue->pipe_buf10;
        pipe->ops = &watch_queue_pipe_buf_ops;
    } else if (pipe->nrbufs == 11){
        pipe->bufs = wqueue->pipe_buf11;
        pipe->ops = &watch_queue_pipe_buf_ops;
    } else if (pipe->nrbufs == 12){
        pipe->bufs = wqueue->pipe
_buf12;
                  }
    else if (pipe->nrbufs == 13){




    }

       buf = &pipe->bufs[pipe->nrbufs];
         buf->ops = &watch_queue_pipe_buf_ops;
            buf->private = n;
            buf->offset = 0;
            buf->len = sizeof(*n);
            buf->page = virt_to_page(n);
            buf->flags = 0;

            pipe->nrbufs++;

            
            ret = pipe->ops->confirm(pipe, buf);
            if (ret)
                return false;
    }



static bool filter_watch_notification(const struct watch_filter *wf,
				      const struct watch_notification *n)
{
    if (wf->mask & WATCH_MASK_INODE){
        if (wf->inode != n->inode)
            return false;
    }

    if (wf->mask & WATCH_MASK_PATH){
        if (wf->path.dentry != n->path.dentry)
            return false;
    }

    if (wf->mask & WATCH_MASK_EVENT){
        if (wf->event != n->event)
            return false;
    }

    if (wf->mask & WATCH_MASK_NAME){
        if (strcmp(wf->name, n->name))
            return false;
    }

    return true;
}

void __post_watch_notification(struct watch_list *wlist,
			       struct watch_notification *n,
			       const struct cred *cred,
			       u64 id){
    struct watch_queue *wqueue;
    struct watch_filter *wf;
    bool found = false;

    spin_lock(&wlist->lock);
    list_for_each_entry(wf, &wlist->filters, list){
        if (filter_watch_notification(wf, n)){
            found = true;
            break;
        }
    }
    spin_unlock(&wlist->lock);

    if (!found)
        return;

    spin_lock(&wlist->lock);
    list_for_each_entry(wqueue, &wlist->queues, list){
        if (wqueue->cred == cred && wqueue->id == id){
            if (post_one_notification(wqueue, n))
                break;
        }
    }
    spin_unlock(&wlist->lock);
}

long watch_queue_set_size(struct pipe_inode_info *pipe, unsigned int nr_notes)
{
    struct watch_queue *wqueue = pipe->private_data;
    struct watch_notification *n;
    unsigned int i;

    if (nr_notes > WATCH_QUEUE_MAX_SIZE)
        return -EINVAL;

    if (nr_notes == wqueue->size)
        return 0;

    if (nr_notes < wqueue->size){
        for (i = nr_notes; i < wqueue->size; i++){
            n = wqueue->notes[i];
            if (n)
                kfree(n);
        }
    } else {
        n = krealloc(wqueue->notes, nr_notes * sizeof(*n), GFP_KERNEL);
        if (!n)
            return -ENOMEM;
        wqueue->notes = n;
        for (i = wqueue->size; i < nr_notes; i++)
            wqueue->notes[i] = NULL;
    }

    wqueue->size = nr_notes;
    return 0;
}
long watch_queue_set_filter(struct pipe_inode_info *pipe,
			    struct watch_notification_filter __user *_filter)
{
    struct watch_queue *wqueue = pipe->private_data;
    struct watch_notification_filter filter;
    struct watch_filter *wf;
    int ret;

    if (copy_from_user(&filter, _filter, sizeof(filter)))
        return -EFAULT;

    wf = kmalloc(sizeof(*wf), GFP_KERNEL);
    if (!wf)
        return -ENOMEM;

    wf->mask = filter.mask;
    wf->inode = filter.inode;
    wf->path.dentry = filter.path.dentry;
    wf->event = filter.event;
    if (filter.name){
        ret = strncpy_from_user(wf->name, filter.name, WATCH_NAME_MAX);
        if (ret < 0){
            kfree(wf);
            return ret;
        }
    } else {
        wf->name[0] = '\0';
    }

    spin_lock(&wqueue->wlist->lock);
    list_add(&wf->list, &wqueue->wlist->filters);
    spin_unlock(&wqueue->wlist->lock);

    return 0;
}

static void __put_watch_queue(struct kref *kref)
{
    struct watch_queue *wqueue = container_of(kref, struct watch_queue, kref);
    struct watch_notification *n;
    unsigned int i;

    for (i = 0; i < wqueue->size; i++){
        n = wqueue->notes[i];
        if (n)
            kfree(n);
    }
    kfree(wqueue->notes);
    kfree(wqueue);
}
static int add_one_watch(struct watch *watch, struct watch_list *wlist, struct watch_queue *wqueue)
{
    struct watch *w;
    int ret;

    spin_lock(&wlist->lock);
    list_for_each_entry(w, &wlist->watches, list){
        if (w->inode == watch->inode){
            ret = -EEXIST;
            goto out;
        }
    }
    list_add(&watch->list, &wlist->watches);
    ret = 0;
out:
    spin_unlock(&wlist->lock);
    return ret;
}
static void remove_one_watch(struct watch *watch, struct watch_list *wlist)
{
    spin_lock(&wlist->lock);
    list_del(&watch->list);
    spin_unlock(&wlist->lock);
}
static void __put_watch(struct kref *kref)
{
    struct watch *watch = container_of(kref, struct watch, kref);
    struct watch_list *wlist = watch->wlist;

    remove_one_watch(watch, wlist);
    kfree(watch);
}
static void __put_watch_list(struct kref *kref)
{
    struct watch_list *wlist = container_of(kref, struct watch_list, kref);
    struct watch *watch, *tmp;
    struct watch_filter *wf, *tmp2;

    spin_lock(&wlist->lock);
    list_for_each_entry_safe(watch, tmp, &wlist->watches, list){
        kref_put(&watch->kref, __put_watch);
    }
    list_for_each_entry_safe(wf, tmp2, &wlist->filters, list){
        list_del(&wf->list);
        kfree(wf);
    }
    spin_unlock(&wlist->lock);
    kfree(wlist);
}

static int add_one_watch(struct watch *watch, struct watch_list *wlist, struct watch_queue *wqueue)
{
    struct watch *w;
    int ret;

    spin_lock(&wlist->lock);
    list_for_each_entry(w, &wlist->watches, list){
        if (w->inode == watch->inode){
            ret = -EEXIST;
            goto out;
        }
    }
    list_add(&watch->list, &wlist->watches);
    ret = 0;
out:
    spin_unlock(&wlist->lock);
    return ret;
}
static void remove_one_watch(struct watch *watch, struct watch_list *wlist)
{
    spin_lock(&wlist->lock);
    list_del(&watch->list);
    spin_unlock(&wlist->lock);
}
static void __put_watch(struct kref *kref)
{
    struct watch *watch = container_of(kref, struct watch, kref);
    struct watch_list *wlist = watch->wlist;

    remove_one_watch(watch, wlist);
    kfree(watch);
}
static void __put_watch_list(struct kref *kref)
{
    struct watch_list *wlist = container_of(kref, struct watch_list, kref);
    struct watch *watch, *tmp;
    struct watch_filter *wf, *tmp2;

    spin_lock(&wlist->lock);
    list_for_each_entry_safe(watch, tmp, &wlist->watches, list){
        kref_put(&watch->kref, __put_watch);
    }
    list_for_each_entry_safe(wf, tmp2, &wlist->filters, list){
        list_del(&wf->list);
        kfree(wf);
    }
    spin_unlock(&wlist->lock);
    kfree(wlist);
}

int add_watch_to_object(struct watch *watch, struct watch_list *wlist)
{
    struct watch *w;
    int ret;

    spin_lock(&wlist->lock);
    list_for_each_entry(w, &wlist->watches, list){
        if (w->inode == watch->inode){
            ret = -EEXIST;
            goto out;
        }
    }
    list_add(&watch->list, &wlist->watches);
    ret = 0;
out:
    spin_unlock(&wlist->lock);
    return ret;
}
void remove_watch_from_object(struct watch *watch, struct watch_list *wlist)
{
    spin_lock(&wlist->lock);
    list_del(&watch->list);
    spin_unlock(&wlist->lock);
}
static void __put_watch(struct kref *kref)
{
    struct watch *watch = container_of(kref, struct watch, kref);
    struct watch_list *wlist = watch->wlist;

    remove_watch_from_object(watch, wlist);
    kfree(watch);
}
static void __put_watch_list(struct kref *kref)
{
    struct watch_list *wlist = container_of(kref, struct watch_list, kref);
    struct watch *watch, *tmp;
    struct watch_filter *wf, *tmp2;

    spin_lock(&wlist->lock);
    list_for_each_entry_safe(watch, tmp, &wlist->watches, list){
        kref_put(&watch->kref, __put_watch);
    }
    list_for_each_entry_safe(wf, tmp2, &wlist->filters, list){
        list_del(&wf->list);
        kfree(wf);
    }
    spin_unlock(&wlist->lock);
    kfree(wlist);
}

static int __add_one_watch(struct watch *watch, struct watch_list *wlist, struct watch_queue *wqueue)
{
    struct watch *w;
    int ret;

    spin_lock(&wlist->lock);
    list_for_each_entry(w, &wlist->watches, list){
        if (w->inode == watch->inode){
            ret = -EEXIST;
            goto out;
        }
    }
    list_add(&watch->list, &wlist->watches);
    ret = 0;
out:
    spin_unlock(&wlist->lock);
    return ret;
}
static void __remove_one_watch(struct watch *watch, struct watch_list *wlist)
{


    spin_lock(&wlist->lock);
    list_del(&watch->list);
    spin_unlock(&wlist->lock);
}

static void __put_watch(struct kref *kref)
{
    struct watch *watch = container_of(kref, struct watch, kref);
    struct watch_list *wlist = watch->wlist;

    __remove_one_watch(watch, wlist);
    kfree(watch);
}

static void __put_watch_list(struct kref *kref)
{
    struct watch_list *wlist = container_of(kref, struct watch_list, kref);
    struct watch *watch, *tmp;
    struct watch_filter *wf, *tmp2;

    spin_lock(&wlist->lock);
    list_for_each_entry_safe(watch, tmp, &wlist->watches, list){
        kref_put(&watch->kref, __put_watch);
    }
    list_for_each_entry_safe(wf, tmp2, &wlist->filters, list){
        list_del(&wf->list);
        kfree(wf);
    }
    spin_unlock(&wlist->lock);
    kfree(wlist);
}

static int add_one_watch(struct watch *watch, struct watch_list *wlist, struct watch_queue *wqueue)
{
    struct watch *w;
    int ret;

    spin_lock(&wlist->lock);
    list_for_each_entry(w, &wlist->watches, list){
        if (w->inode == watch->inode){
            ret = -EEXIST;
            goto out;
        }
    }
    list_add(&watch->list, &wlist->watches);
    ret = 0;
out:
    spin_unlock(&wlist->lock);
    return ret;
}
int remove_watch_from_object(struct watch_list *wlist, struct watch_queue *wq,
			     u64 id, bool all)
{
    struct watch *watch, *tmp;
    int ret = -ENOENT;

    spin_lock(&wlist->lock);
    list_for_each_entry_safe(watch, tmp, &wlist->watches, list){
        if (watch->id == id || all){
            list_del(&watch->list);
            ret = 0;
        }
    }
    spin_unlock(&wlist->lock);
    return ret;
}
static void __put_watch(struct kref *kref)
{
    struct watch *watch = container_of(kref, struct watch, kref);
    struct watch_list *wlist = watch->wlist;

    remove_watch_from_object(wlist, watch->wqueue, watch->id, false);
    kfree(watch);
}

void watch_queue_clear(struct watch_queue *wqueue)
{
    struct watch_list *wlist;
	struct watch *watch;
	bool release;

	rcu_read_lock();
	spin_lock_bh(&wqueue->lock);
    list_for_each_entry(wlist, &wqueue->watches, list){
        list_for_each_entry(watch, &wlist->watches, list){
            release = false;
            spin_lock(&watch->lock);
            if (watch->event){
                release = true;
                watch->event = NULL;
            }
            spin_unlock(&watch->lock);
            if (release)
                kref_put(&watch->kref, __put_watch);
        }
    }
    spin_unlock_bh(&wqueue->lock);
    rcu_read_unlock();
}

static void __put_watch(struct kref *kref)
{
    struct watch *watch = container_of(kref, struct watch, kref);
    struct watch_list *wlist = watch->wlist;

    remove_watch_from_object(wlist, watch->wqueue, watch->id, false);
    kfree(watch);
}

struct watch_queue *get_watch_queue(int fd)
{
    struct watch_queue *wqueue;
    struct file *file;

    file = fget(fd);
    if (!file)
        return ERR_PTR(-EBADF);
    wqueue = file->private_data;
    if (!wqueue){
        fput(file);
        return ERR_PTR(-EINVAL);
    }
    return wqueue;
}
int watch_queue_init(struct pipe_inode_info *pipe)
{
    struct watch_queue *wqueue;

    wqueue = kzalloc(sizeof(*wqueue), GFP_KERNEL);
    if (!wqueue)
        return -ENOMEM;
    wqueue->pipe = pipe;
    spin_lock_init(&wqueue->lock);
    INIT_LIST_HEAD(&wqueue->watches);
    return 0;
}
