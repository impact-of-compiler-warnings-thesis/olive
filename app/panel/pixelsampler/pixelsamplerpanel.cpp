/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2022 Olive Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#include "pixelsamplerpanel.h"

#include "core.h"

namespace olive {

PixelSamplerPanel::PixelSamplerPanel(QWidget *parent) :
  PanelWidget(QStringLiteral("PixelSamplerPanel"), parent)
{
  sampler_widget_ = new ManagedPixelSamplerWidget();
  SetWidgetWithPadding(sampler_widget_);

  connect(this, &PixelSamplerPanel::visibilityChanged, Core::instance(), &Core::RequestPixelSamplingInViewers);
  connect(Core::instance(), &Core::ColorPickerColorEmitted, this, &PixelSamplerPanel::SetValues);

  Retranslate();
}

void PixelSamplerPanel::SetValues(const Color &reference, const Color &display)
{
  sampler_widget_->SetValues(reference, display);
}

void PixelSamplerPanel::Retranslate()
{
  SetTitle(tr("Pixel Sampler"));
}

}
