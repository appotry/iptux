//
// C++ Interface: DialogGroup
//
// Description:
// 与多人对话
//
// Author: Jally <jallyx@163.com>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef IPTUX_DIALOGGROUP_H
#define IPTUX_DIALOGGROUP_H

#include "iptux/DialogBase.h"
#include "iptux/IptuxConfig.h"
#include "iptux/ProgramData.h"
#include "iptux/mess.h"

namespace iptux {

class DialogGroup : public DialogBase {
 public:
  DialogGroup(GroupInfo *grp, IptuxConfig &config, ProgramData &progdt);
  virtual ~DialogGroup();

  static void GroupDialogEntry(IptuxConfig &config, GroupInfo *grpinf,
                               ProgramData &progdt);

  virtual void UpdatePalData(PalInfo *pal);
  virtual void InsertPalData(PalInfo *pal);
  virtual void DelPalData(PalInfo *pal);
  virtual void ClearAllPalData();
  virtual GSList *GetSelPal();

 private:
  IptuxConfig &config;
  virtual void InitSublayerSpecify();
  void ReadUILayout();
  void SaveUILayout();

  GtkWidget *CreateMainWindow();
  GtkWidget *CreateAllArea();

  GtkWidget *CreateMenuBar();
  GtkWidget *CreateMemberArea();
  GtkWidget *CreateInputArea();
  GtkWidget *CreateToolMenu();

  GtkTreeModel *CreateMemberModel();
  void FillMemberModel(GtkTreeModel *model);
  GtkWidget *CreateMemberTree(GtkTreeModel *model);

  bool SendTextMsg();

 private:
  void BroadcastEnclosureMsg(GSList *list);
  void BroadcastTextMsg(const gchar *msg);

  static GtkWidget *CreatePopupMenu(GtkTreeModel *model);
  //回调处理部分
 private:
  static gint MemberTreeCompareByNameFunc(GtkTreeModel *model, GtkTreeIter *a,
                                          GtkTreeIter *b);
  static gint MemberTreeCompareByIPFunc(GtkTreeModel *model, GtkTreeIter *a,
                                        GtkTreeIter *b);
  static void SetMemberTreeSortFunc(GtkWidget *menuitem, GtkTreeModel *model);
  static void SetMemberTreeSortType(GtkWidget *menuitem, GtkTreeModel *model);
  static void DragDataReceived(DialogGroup *dlggrp, GdkDragContext *context,
                               gint x, gint y, GtkSelectionData *data,
                               guint info, guint time);
  static gboolean PopupPickMenu(GtkWidget *treeview, GdkEventButton *event);
  static void MembertreeItemActivated(GtkWidget *treeview, GtkTreePath *path,
                                      GtkTreeViewColumn *column,
                                      DialogGroup *self);
  static void SendMessage(DialogGroup *dlggrp);
};

}  // namespace iptux

#endif